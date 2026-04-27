#include "StudentRegistry.h"
#include <iostream>
using namespace std;

// Pre-registered Student IDs from the official list (95 IDs)
const string StudentRegistry::registeredIDs[TOTAL_REGISTERED] = {
    "1023","4587","7691","2345","8901","6732","1456","9087","3214","5678",
    "7823","1190","4456","9902","8741","6603","2874","5312","7489","9021",
    "3847","6150","2709","8534","4261","7098","3321","5843","9610","2478",
    "1357","2468","3579","4680","5791","6802","7913","8024","9135","1246",
    "2357","3468","4579","5680","6791","7802","8913","9024","2135","3246",
    "4357","5468","6579","7680","8791","9802","1913","2024","3135","4246",
    "5357","6468","7579","8680","9791","1082","2193","3204","4315","5426",
    "6537","7648","8759","9860","1971","2082","3193","4204","5315","6426",
    "7537","8648","9759","1860","2971","3082","4193","5204","6315","7426",
    "8537","9648","1759","2860","0000"  // 0000 = placeholder to reach array size
};

// Default display names (students will enter their real name on first login)
const string StudentRegistry::registeredNames[TOTAL_REGISTERED] = {
    "Student 1023","Student 4587","Student 7691","Student 2345","Student 8901",
    "Student 6732","Student 1456","Student 9087","Student 3214","Student 5678",
    "Student 7823","Student 1190","Student 4456","Student 9902","Student 8741",
    "Student 6603","Student 2874","Student 5312","Student 7489","Student 9021",
    "Student 3847","Student 6150","Student 2709","Student 8534","Student 4261",
    "Student 7098","Student 3321","Student 5843","Student 9610","Student 2478",
    "Student 1357","Student 2468","Student 3579","Student 4680","Student 5791",
    "Student 6802","Student 7913","Student 8024","Student 9135","Student 1246",
    "Student 2357","Student 3468","Student 4579","Student 5680","Student 6791",
    "Student 7802","Student 8913","Student 9024","Student 2135","Student 3246",
    "Student 4357","Student 5468","Student 6579","Student 7680","Student 8791",
    "Student 9802","Student 1913","Student 2024","Student 3135","Student 4246",
    "Student 5357","Student 6468","Student 7579","Student 8680","Student 9791",
    "Student 1082","Student 2193","Student 3204","Student 4315","Student 5426",
    "Student 6537","Student 7648","Student 8759","Student 9860","Student 1971",
    "Student 2082","Student 3193","Student 4204","Student 5315","Student 6426",
    "Student 7537","Student 8648","Student 9759","Student 1860","Student 2971",
    "Student 3082","Student 4193","Student 5204","Student 6315","Student 7426",
    "Student 8537","Student 9648","Student 1759","Student 2860","Unknown"
};

bool StudentRegistry::isRegistered(const string& studentID) {
    for (int i = 0; i < TOTAL_REGISTERED - 1; i++) { // -1 to skip placeholder
        if (registeredIDs[i] == studentID)
            return true;
    }
    return false;
}

string StudentRegistry::getNameByID(const string& studentID) {
    for (int i = 0; i < TOTAL_REGISTERED - 1; i++) {
        if (registeredIDs[i] == studentID)
            return registeredNames[i];
    }
    return "";
}
