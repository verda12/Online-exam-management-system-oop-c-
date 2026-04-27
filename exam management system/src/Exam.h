#ifndef EXAM_H
#define EXAM_H

#include "Question.h"
#include <string>
using namespace std;

const int QUESTIONS_PER_EXAM = 20;

class Exam {
private:
    string courseName;
    string courseCode;
    Question questions[QUESTIONS_PER_EXAM];
    int questionCount;

public:
    Exam();
    Exam(const string& name, const string& code);

    void addQuestion(const Question& q);
    string getCourseName() const;
    string getCourseCode() const;
    int getQuestionCount() const;
    const Question& getQuestion(int index) const;
    bool isReady() const;
};

#endif
