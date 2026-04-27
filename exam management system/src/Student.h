#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

const int MAX_RESULTS = 10;

struct ExamResult {
    string courseCode;
    string courseName;
    int score;
    int totalQuestions;
    char grade;
    string date;
};

class Student {
private:
    string studentID;
    string studentName;
    ExamResult results[MAX_RESULTS];
    int resultCount;

public:
    Student();
    Student(const string& id, const string& name);

    string getStudentID() const;
    string getStudentName() const;
    int getResultCount() const;
    const ExamResult& getResult(int index) const;

    void addResult(const ExamResult& result);
    void displayResults() const;
    bool hasAttempted(const string& courseCode) const;
};

#endif
