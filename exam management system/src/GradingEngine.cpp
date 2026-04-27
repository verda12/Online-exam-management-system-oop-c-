#include "GradingEngine.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

char GradingEngine::calculateGrade(int score, int total) {
    double pct = calculatePercentage(score, total);
    if (pct >= 90) return 'A';
    if (pct >= 80) return 'B';
    if (pct >= 70) return 'C';
    if (pct >= 60) return 'D';
    return 'F';
}

double GradingEngine::calculatePercentage(int score, int total) {
    if (total == 0) return 0.0;
    return (static_cast<double>(score) / total) * 100.0;
}

ExamResult GradingEngine::gradeExam(const string& courseCode, const string& courseName,
                                     const char userAnswers[], const Exam& exam) {
    ExamResult result;
    result.courseCode     = courseCode;
    result.courseName     = courseName;
    result.totalQuestions = exam.getQuestionCount();
    result.score          = 0;

    for (int i = 0; i < exam.getQuestionCount(); i++) {
        if (exam.getQuestion(i).checkAnswer(userAnswers[i]))
            result.score++;
    }

    result.grade = calculateGrade(result.score, result.totalQuestions);

    time_t now = time(0);
    tm* ltm = localtime(&now);
    char dateBuf[32];
    sprintf(dateBuf, "%02d/%02d/%04d",
            ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);
    result.date = string(dateBuf);

    return result;
}

void GradingEngine::displayResult(const ExamResult& result) {
    double pct = calculatePercentage(result.score, result.totalQuestions);

    ostringstream scoreStr;
    scoreStr << result.score << " / " << result.totalQuestions;

    ostringstream pctStr;
    pctStr << fixed << setprecision(1) << pct << "%";

    cout << "\n";
    cout << "  ============================================\n";
    cout << "  |        EXAM RESULT SUMMARY             |\n";
    cout << "  ============================================\n";
    cout << "  |  Course  : " << left << setw(30) << result.courseName              << "|\n";
    cout << "  |  Code    : " << left << setw(30) << result.courseCode              << "|\n";
    cout << "  |  Score   : " << left << setw(30) << scoreStr.str()                 << "|\n";
    cout << "  |  Percent : " << left << setw(30) << pctStr.str()                   << "|\n";
    cout << "  |  Grade   : " << left << setw(30) << result.grade                   << "|\n";
    cout << "  |  Remark  : " << left << setw(30) << getGradeRemark(result.grade)   << "|\n";
    cout << "  |  Date    : " << left << setw(30) << result.date                    << "|\n";
    cout << "  ============================================\n";
}

string GradingEngine::getGradeRemark(char grade) {
    switch (grade) {
        case 'A': return "Outstanding!";
        case 'B': return "Very Good!";
        case 'C': return "Good";
        case 'D': return "Satisfactory";
        case 'F': return "Failed - Study Harder";
        default:  return "N/A";
    }
}
