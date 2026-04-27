#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sys/stat.h>
#ifdef _WIN32
    #include <direct.h>
#endif
using namespace std;

void FileManager::ensureDataDirectory() {
#ifdef _WIN32
    _mkdir("data");
#else
    mkdir("data", 0755);
#endif
}

string FileManager::getResultsFilePath(const string& studentID) {
    return "data/" + studentID + "_results.txt";
}

bool FileManager::studentFileExists(const string& studentID) {
    string path = getResultsFilePath(studentID);
    ifstream f(path.c_str());
    return f.good();
}

// Read the student name from the first line of their results file
string FileManager::getStudentName(const string& studentID) {
    string path = getResultsFilePath(studentID);
    ifstream file(path.c_str());
    if (!file.is_open()) return "";

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        if (!line.empty() && line[line.size()-1] == '\r')
            line.erase(line.size()-1);

        // Format: NAME|ID|...
        string name = "";
        for (int i = 0; i < (int)line.size(); i++) {
            if (line[i] == '|') break;
            name += line[i];
        }
        file.close();
        return name;
    }
    file.close();
    return "";
}

bool FileManager::saveStudentResult(const Student& student, const ExamResult& result) {
    ensureDataDirectory();
    string path = getResultsFilePath(student.getStudentID());

    ofstream file(path.c_str(), ios::app);
    if (!file.is_open()) {
        cerr << "  [ERROR] Could not open file for writing: " << path << "\n";
        return false;
    }

    // Format: NAME|STUDENT_ID|COURSE_CODE|COURSE_NAME|SCORE|TOTAL|GRADE|DATE
    file << student.getStudentName() << "|"
         << student.getStudentID()   << "|"
         << result.courseCode        << "|"
         << result.courseName        << "|"
         << result.score             << "|"
         << result.totalQuestions    << "|"
         << result.grade             << "|"
         << result.date              << "\n";

    file.close();
    return true;
}

bool FileManager::loadStudentResults(Student& student) {
    string path = getResultsFilePath(student.getStudentID());
    ifstream file(path.c_str());
    if (!file.is_open()) return false;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        if (!line.empty() && line[line.size()-1] == '\r')
            line.erase(line.size()-1);

        ExamResult result;
        string tokens[8];
        int tokenIndex = 0;
        string current = "";

        for (int i = 0; i < (int)line.size(); i++) {
            char ch = line[i];
            if (ch == '|') {
                if (tokenIndex < 8) tokens[tokenIndex++] = current;
                current = "";
            } else {
                current += ch;
            }
        }
        if (tokenIndex < 8) tokens[tokenIndex++] = current;
        if (tokenIndex < 8) continue;

        result.courseCode     = tokens[2];
        result.courseName     = tokens[3];
        result.score          = atoi(tokens[4].c_str());
        result.totalQuestions = atoi(tokens[5].c_str());
        result.grade          = tokens[6][0];
        result.date           = tokens[7];

        student.addResult(result);
    }

    file.close();
    return true;
}
