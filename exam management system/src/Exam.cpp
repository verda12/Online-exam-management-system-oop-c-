#include "Exam.h"
#include <iostream>
using namespace std;

Exam::Exam() : courseName(""), courseCode(""), questionCount(0) {}

Exam::Exam(const string& name, const string& code)
    : courseName(name), courseCode(code), questionCount(0) {}

void Exam::addQuestion(const Question& q) {
    if (questionCount < QUESTIONS_PER_EXAM) {
        questions[questionCount++] = q;
    }
}

string Exam::getCourseName() const {
    return courseName;
}

string Exam::getCourseCode() const {
    return courseCode;
}

int Exam::getQuestionCount() const {
    return questionCount;
}

const Question& Exam::getQuestion(int index) const {
    return questions[index];
}

bool Exam::isReady() const {
    return questionCount == QUESTIONS_PER_EXAM;
}
