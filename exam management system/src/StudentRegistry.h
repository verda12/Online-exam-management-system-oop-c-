#ifndef STUDENT_REGISTRY_H
#define STUDENT_REGISTRY_H

#include <string>
using namespace std;

const int TOTAL_REGISTERED = 95;

class StudentRegistry {
private:
    static const string registeredIDs[TOTAL_REGISTERED];
    static const string registeredNames[TOTAL_REGISTERED];

public:
    static bool isRegistered(const string& studentID);
    static string getNameByID(const string& studentID);
};

#endif
