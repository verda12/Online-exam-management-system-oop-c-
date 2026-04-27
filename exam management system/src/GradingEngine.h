#ifndef GRADING_ENGINE_H
#define GRADING_ENGINE_H

#include "Student.h"
#include "Exam.h"
#include <string>
using namespace std;

class GradingEngine {
public:
    static char calculateGrade(int score, int total);
    static double calculatePercentage(int score, int total);
    static ExamResult gradeExam(const string& courseCode, const string& courseName,
                                 const char userAnswers[], const Exam& exam);
    static void displayResult(const ExamResult& result);
    static string getGradeRemark(char grade);
};

#endif
