// A simple quiz program in C++
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// A struct to store a question and its answer
struct Question {
  string question;
  string answer;
};

// A vector of questions
vector<Question> questions = {
  {"What is the capital of Nepal?", "Kathmandu"},
  {"Who is the author of Harry Potter series?", "J.K. Rowling"},
  {"What is the name of the largest bone in the human body?", "Femur"},
  {"Which planet is the second smallest in the solar system?", "Mars"},
  {"What is the name of the phobia that means fear of spiders?", "Arachnophobia"}
};

// A function to shuffle the questions
void shuffle_questions() {
  srand(time(0)); // seed the random number generator
  for (int i = 0; i < questions.size(); i++) {
    int j = rand() % questions.size(); // pick a random index
    swap(questions[i], questions[j]); // swap the questions
  }
}

// A function to display a question and get the user's answer
string ask_question(Question q) {
  cout << q.question << "\n"; // display the question
  string user_answer; // declare a variable to store the user's answer
  getline(cin, user_answer); // get the user's answer
  return user_answer; // return the user's answer
}

// A function to check if the user's answer is correct and display feedback
bool check_answer(string user_answer, string correct_answer) {
  if (user_answer == correct_answer) { // if the user's answer is correct
    cout << "Correct!\n"; // display positive feedback
    return true; // return true
  }
  else { // if the user's answer is incorrect
    cout << "Wrong. The correct answer is " << correct_answer << ".\n"; // display negative feedback and the correct answer
    return false; // return false
  }
}

// A function to run the quiz and display the score
void run_quiz() {
  int score = 0; // declare and initialize a variable to store the score
  shuffle_questions(); // shuffle the questions
  for (int i = 0; i < questions.size(); i++) { // loop through the questions
    string user_answer = ask_question(questions[i]); // ask a question and get the user's answer
    bool result = check_answer(user_answer, questions[i].answer); // check if the user's answer is correct and get the result
    if (result) { // if the result is true
      score++; // increment the score
    }
    cout << "\n"; // print a newline for spacing
  }
  cout << "You scored " << score << " out of " << questions.size() << ".\n"; // display the final score
}

// The main function
int main() {
  cout << "Welcome to the quiz!\n"; // display a welcome message
  cout << "You will be asked " << questions.size() << " questions.\n"; // display the number of questions
  cout << "Type your answer and press enter.\n"; // display the instructions
  cout << "\n"; // print a newline for spacing
  run_quiz(); // run the quiz
  return 0; // exit the program
}
