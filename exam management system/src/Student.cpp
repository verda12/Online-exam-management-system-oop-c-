#include "Student.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Student::Student() : studentID(""), studentName(""), resultCount(0) {}

Student::Student(const string& id, const string& name)
    : studentID(id), studentName(name), resultCount(0) {}

string Student::getStudentID() const { return studentID; }
string Student::getStudentName() const { return studentName; }
int Student::getResultCount() const { return resultCount; }
const ExamResult& Student::getResult(int index) const { return results[index]; }

void Student::addResult(const ExamResult& result) {
    if (resultCount < MAX_RESULTS)
        results[resultCount++] = result;
}

void Student::displayResults() const {
    if (resultCount == 0) {
        cout << "\n  No exam results found for student: " << studentName << "\n";
        return;
    }

    cout << "\n";
    cout << "  ================================================================\n";
    cout << "  |  EXAM RESULTS FOR : " << left << setw(42) << studentName << "|\n";
    cout << "  |  Student ID       : " << left << setw(42) << studentID   << "|\n";
    cout << "  ================================================================\n";
    cout << "  | Code       | Course Name              | Score | Grd | Date   |\n";
    cout << "  ================================================================\n";

    for (int i = 0; i < resultCount; i++) {
        ostringstream scoreStr;
        scoreStr << results[i].score << "/" << results[i].totalQuestions;
        cout << "  | " << left << setw(11) << results[i].courseCode
             << "| "   << left << setw(25) << results[i].courseName
             << "| "   << left << setw(6)  << scoreStr.str()
             << "| "   << left << setw(4)  << results[i].grade
             << "| "   << left << setw(7)  << results[i].date
             << "|\n";
    }
    cout << "  ================================================================\n";
}

bool Student::hasAttempted(const string& courseCode) const {
    for (int i = 0; i < resultCount; i++) {
        if (results[i].courseCode == courseCode)
            return true;
    }
    return false;
}
