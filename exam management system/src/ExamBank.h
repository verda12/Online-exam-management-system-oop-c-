#ifndef EXAM_BANK_H
#define EXAM_BANK_H

#include "Exam.h"

const int TOTAL_COURSES = 3;

class ExamBank {
private:
    Exam courses[TOTAL_COURSES];
    int courseCount;

    void loadOOPExam();
    void loadDSAExam();
    void loadOSExam();

public:
    ExamBank();
    int getCourseCount() const;
    const Exam& getCourse(int index) const;
    void displayCourseMenu() const;
    int selectCourse() const;
};

#endif
