#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#define MAX 70
#define MAXSUB 5
using namespace std;

struct dateType {
    int dd, mm, yy;
};

struct nameType {
    string fname;
    string lname;
};

// Start: Student Time Class

class stdTime {
    unsigned int hour;
    unsigned int min;
    unsigned int sec;

public:
    void getter();
    void setter();
    // Operator Overloading for comparing In-Time or Out-Time
    bool operator> (stdTime obj);

    stdTime():hour(0), min(0), sec(0) {}
};

// End: Student Time Class

// Start: Student Class

class student {
    int regno;
    nameType name;
    int marks[MAXSUB];
    int totalMarks;
    double gpa, prc;
    stdTime inTime;
    stdTime outTime;
    dateType dob, doa;

public:
    student() {
        regno = 0;
        totalMarks = 0;
        gpa = 0;
        prc = 0;
        // initializing array
        fill(marks, marks + 5, 0);
        // initializing structure
        dob = { 0, 0, 0 };
        doa = { 0, 0, 0 };
    }
    void setter();
    void getter();
   // void appendRec(int nn);
    int getRegNo();
    void updateRegNo();
    void updateName();
    void updateMarks();
    void updateDoa();
    void updateDob();
    void getStdBio();
};

// End: Student Class

// User Defined Functions
void createDB(int& nn, student std[]);
void resultShow(student std[], int nn, int sPos = -2);
int searchRec(student std[], int nn);
void delRecord(student std[], int& nn);
void updateRecord(student std[], int nn);
void showBio(student std[], int nn);


#endif // !STUDENT_H
