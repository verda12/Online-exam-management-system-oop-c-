#include "Question.h"
#include <iostream>
#include <iomanip>
using namespace std;

Question::Question() : questionText(""), options{"","","",""}, correctAnswer('A') {}

Question::Question(const string& text, const string optArr[4], char correct) {
    questionText = text;
    for (int i = 0; i < 4; i++) options[i] = optArr[i];
    correctAnswer = correct;
}

string Question::getQuestionText() const { return questionText; }
string Question::getOption(int index) const {
    if (index >= 0 && index < 4) return options[index];
    return "";
}
char Question::getCorrectAnswer() const { return correctAnswer; }

bool Question::checkAnswer(char userAnswer) const {
    return (toupper(userAnswer) == toupper(correctAnswer));
}

void Question::display(int questionNumber) const {
    cout << "\n  Q" << questionNumber << ". " << questionText << "\n";
    cout << "     A) " << options[0] << "\n";
    cout << "     B) " << options[1] << "\n";
    cout << "     C) " << options[2] << "\n";
    cout << "     D) " << options[3] << "\n";
    cout << "  Your Answer: ";
}
