# Online Exam Management System
**National University of Computer & Emerging Sciences — Karachi Campus**  
Object Oriented Programming | Section BCS-2E

**Group Members**
- 25k-0962 Briana Riaz
- 25k-0890 Verda

---

## Project Overview

A fully console-based, offline Online Exam Management System built in **C++17** using
Object-Oriented Programming principles. Students can log in, take MCQ-based exams
across multiple courses, receive instant graded results, and have their records
persisted to disk for future retrieval.

---

## Features

| Feature | Detail |
|---|---|
| Student Login | Unique Student ID — no password needed |
| Multiple Courses | 3 courses, each with 20 MCQs |
| Automatic Grading | Evaluated instantly on submission |
| Instant Result Display | Score, percentage, grade letter & remark |
| Persistent Storage | Results saved to `data/<StudentID>_results.txt` |
| Re-attempt Prevention | Each course can only be attempted once |
| Fully Offline | No internet or server required |

---

## Project Structure

```
OnlineExamSystem/
├── main.cpp               ← Application entry point & UI flow
├── Makefile               ← Build script
├── README.md
├── include/
│   ├── Question.h         ← MCQ question class
│   ├── Exam.h             ← Course exam container
│   ├── Student.h          ← Student identity & result history
│   ├── GradingEngine.h    ← Grading & result logic
│   ├── FileManager.h      ← File I/O for persistent storage
│   └── ExamBank.h         ← All pre-loaded course questions
└── src/
    ├── Question.cpp
    ├── Exam.cpp
    ├── Student.cpp
    ├── GradingEngine.cpp
    ├── FileManager.cpp
    └── ExamBank.cpp
```

---

## OOP Class Design

```
Question        — stores text, 4 options, correct answer; validates user input
Exam            — holds an array of Questions for one course
Student         — stores ID, name, and up to 10 ExamResult records
GradingEngine   — static methods: grade calculation, result display
FileManager     — static methods: save/load student results via fstream
ExamBank        — aggregates all Exam objects; provides course selection menu
```

---

## Available Courses

| # | Code   | Course Name                        |
|---|--------|------------------------------------|
| 1 | CS-201 | Object-Oriented Programming        |
| 2 | CS-301 | Data Structures & Algorithms       |
| 3 | CS-401 | Operating Systems                  |

---

## Grading Scale

| Grade | Percentage |
|-------|-----------|
| A     | 90 – 100% |
| B     | 80 – 89%  |
| C     | 70 – 79%  |
| D     | 60 – 69%  |
| F     | Below 60% |

---

## How to Build & Run

### Linux / macOS
```bash
cd OnlineExamSystem
make
./ExamSystem
```

### Windows (MinGW)
```bash
cd OnlineExamSystem
g++ -std=c++17 -Wall -o ExamSystem.exe main.cpp src/Question.cpp src/Exam.cpp src/Student.cpp src/GradingEngine.cpp src/FileManager.cpp src/ExamBank.cpp
ExamSystem.exe
```

### Windows (Visual Studio)
Create a new **Empty C++ Project**, add all `.cpp` files under `src/` plus `main.cpp`,
set language standard to **C++17**, and build.

---

## Data Storage

Results are saved in the `data/` directory automatically created at runtime.  
Each student gets their own file: `data/<StudentID>_results.txt`

File format (pipe-delimited):
```
StudentName|StudentID|CourseCode|CourseName|Score|Total|Grade|Date
```

Example:
```
Briana Riaz|25k-0962|CS-201|Object-Oriented Programming|17|20|A|23/04/2026
```
