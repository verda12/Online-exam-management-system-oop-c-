#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

class Question {
private:
    string questionText;
    string options[4];
    char correctAnswer;

public:
    Question();
    Question(const string& text, const string optArr[4], char correct);

    string getQuestionText() const;
    string getOption(int index) const;
    char getCorrectAnswer() const;

    bool checkAnswer(char userAnswer) const;
    void display(int questionNumber) const;
};

#endif
