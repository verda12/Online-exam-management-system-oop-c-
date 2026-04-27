// ============================================================
//  Online Exam Management System
//  National University of Computer & Emerging Sciences
//  Karachi Campus - Object Oriented Programming (BCS-2E)
//  Group: Briana Riaz (25k-0962) | Verda (25k-0890)
// ============================================================

#include <iostream>
#include <string>
#include "src/Question.h"
#include "src/Exam.h"
#include "src/Student.h"
#include "src/GradingEngine.h"
#include "src/FileManager.h"
#include "src/ExamBank.h"
#include "src/StudentRegistry.h"

using namespace std;

// ── UI helpers ────────────────────────────────────────────────
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    cout << "\n  Press ENTER to continue...";
    cin.ignore(1000, '\n');
}

void printBanner() {
    cout << "\n";
    cout << "  ============================================================\n";
    cout << "  |      ONLINE EXAM MANAGEMENT SYSTEM  v1.0               |\n";
    cout << "  |  National University of Computer & Emerging Sciences    |\n";
    cout << "  |                  Karachi Campus                         |\n";
    cout << "  ============================================================\n";
}

void printDivider() {
    cout << "  ------------------------------------------------------------\n";
}

// ── Student Login (Registry-locked) ──────────────────────────
Student loginStudent() {
    string studentID;

    while (true) {
        cout << "\n  +---------------------------------------+\n";
        cout << "  |           STUDENT LOGIN               |\n";
        cout << "  +---------------------------------------+\n";
        cout << "  Enter Student ID : ";
        getline(cin, studentID);

        // Check against registry
        if (!StudentRegistry::isRegistered(studentID)) {
            cout << "\n  *** ACCESS DENIED ***\n";
            cout << "  Student ID [" << studentID << "] is not registered.\n";
            cout << "  Only pre-registered students can use this system.\n";
            cout << "  Please check your ID and try again.\n";
            pauseScreen();
            clearScreen();
            printBanner();
            continue;
        }

        // ID is valid - load or create student record
        string studentName;

        if (FileManager::studentFileExists(studentID)) {
            // Returning student - load name from file
            studentName = FileManager::getStudentName(studentID);
            if (studentName.empty()) {
                studentName = StudentRegistry::getNameByID(studentID);
            }
            cout << "\n  Welcome back, " << studentName << "!\n";
        } else {
            // First login - ask for name, create record
            cout << "\n  First time login detected for ID: " << studentID << "\n";
            cout << "  Enter your full name : ";
            getline(cin, studentName);
            if (studentName.empty()) {
                studentName = StudentRegistry::getNameByID(studentID);
            }
            cout << "\n  Welcome, " << studentName << "! Your account is ready.\n";
        }

        Student student(studentID, studentName);
        FileManager::loadStudentResults(student);
        return student;
    }
}

// ── Conduct a single exam ─────────────────────────────────────
void conductExam(Student& student, const Exam& exam) {
    if (student.hasAttempted(exam.getCourseCode())) {
        cout << "\n  [!] You have already attempted: " << exam.getCourseName() << "\n";
        cout << "  Re-attempts are not permitted.\n";
        pauseScreen();
        return;
    }

    clearScreen();
    printBanner();
    cout << "\n  Course  : " << exam.getCourseName()
         << "  (" << exam.getCourseCode() << ")\n";
    cout << "  Student : " << student.getStudentName()
         << "  [" << student.getStudentID() << "]\n";
    printDivider();
    cout << "  Instructions:\n"
         << "    * Answer each question by typing A, B, C, or D.\n"
         << "    * All 20 questions are compulsory.\n"
         << "    * You cannot go back once a question is answered.\n";
    printDivider();
    cout << "  Press ENTER to start the exam...";
    cin.ignore(1000, '\n');

    char userAnswers[QUESTIONS_PER_EXAM];

    for (int i = 0; i < exam.getQuestionCount(); i++) {
        clearScreen();
        cout << "\n  Course: " << exam.getCourseName()
             << "   Question " << (i + 1) << " of " << exam.getQuestionCount() << "\n";
        printDivider();
        exam.getQuestion(i).display(i + 1);

        char answer;
        while (true) {
            cin >> answer;
            answer = toupper(answer);
            if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D') {
                userAnswers[i] = answer;
                cin.ignore(1000, '\n');
                break;
            }
            cout << "  Invalid input. Enter A, B, C, or D: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    // Grade and save
    ExamResult result = GradingEngine::gradeExam(
        exam.getCourseCode(), exam.getCourseName(), userAnswers, exam);

    student.addResult(result);
    FileManager::saveStudentResult(student, result);

    clearScreen();
    printBanner();
    GradingEngine::displayResult(result);
    pauseScreen();
}

// ── Main menu ─────────────────────────────────────────────────
int showMainMenu(const Student& student) {
    cout << "\n";
    cout << "  +---------------------------------------+\n";
    cout << "  |             MAIN MENU                 |\n";
    cout << "  +---------------------------------------+\n";
    cout << "  |  [1]  Take an Exam                    |\n";
    cout << "  |  [2]  View My Results                 |\n";
    cout << "  |  [3]  Logout                          |\n";
    cout << "  |  [0]  Exit System                     |\n";
    cout << "  +---------------------------------------+\n";
    cout << "  Logged in as : " << student.getStudentName() << "\n";
    cout << "  Student ID   : " << student.getStudentID()   << "\n";
    cout << "  Select option: ";

    int choice;
    while (!(cin >> choice) || choice < 0 || choice > 3) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  Invalid option. Try again: ";
    }
    cin.ignore(1000, '\n');
    return choice;
}

// ── Entry point ───────────────────────────────────────────────
int main() {
    ExamBank bank;
    bool systemRunning = true;

    while (systemRunning) {
        clearScreen();
        printBanner();

        Student student = loginStudent();
        bool sessionActive = true;

        while (sessionActive) {
            clearScreen();
            printBanner();
            int menuChoice = showMainMenu(student);

            switch (menuChoice) {
                case 1: {
                    clearScreen();
                    printBanner();
                    int courseChoice = bank.selectCourse();
                    if (courseChoice == -1) break;
                    conductExam(student, bank.getCourse(courseChoice));
                    break;
                }
                case 2:
                    clearScreen();
                    printBanner();
                    student.displayResults();
                    pauseScreen();
                    break;
                case 3:
                    cout << "\n  Logging out " << student.getStudentName() << "...\n";
                    sessionActive = false;
                    break;
                case 0:
                    cout << "\n  Thank you for using Online Exam Management System.\n";
                    cout << "  Goodbye!\n\n";
                    sessionActive = false;
                    systemRunning = false;
                    break;
            }
        }
    }

    return 0;
}
