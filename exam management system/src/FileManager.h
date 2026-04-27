#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Student.h"
#include <string>
using namespace std;

class FileManager {
public:
    static bool saveStudentResult(const Student& student, const ExamResult& result);
    static bool loadStudentResults(Student& student);
    static bool studentFileExists(const string& studentID);
    static string getStudentName(const string& studentID);
    static void ensureDataDirectory();
    static string getResultsFilePath(const string& studentID);
};

#endif
