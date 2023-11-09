#include "student.h"
#include <iostream>

// Start: StdTime Class Member Functions 

void stdTime::setter() {
    do
    {
        cin >> hour >> min >> sec;
        if ((hour < 0 || hour >= 24) || (min < 0 || min >= 60) || (sec < 0 || sec >= 60)) {
            cout << "\nInValid Values for (hour min sec)\n" << endl;
            cout << "Enter time Again (hour min sec) = ";
        }
        else
            break;
    } while (true);
    cout << endl;
}

void stdTime::getter() {
    cout << hour << ":" << min << ":" << sec << endl;
}

// doing operator overloading ( > )
bool stdTime::operator> (stdTime obj) {
    if (hour >= obj.hour) {
        if (min >= obj.min) {
            if (sec > obj.sec) {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

// End: StdTime Class Member Functions

// Start: Student Class Memeber Functions

void student::setter() {
    cout << endl << "Enter student registration number: ";
    cin >> regno;

    cout << endl << "Enter student First Name: ";
    cin.ignore(); // to ignore newline character left in the buffer by cin
    getline(cin, name.fname);

    cout << endl << "Enter student Last Name: ";
    getline(cin, name.lname);

    // getting and validating DOB and DOA
    do
    {
        // individually validating DOB
        do {
            cout << "Enter Date of Birth (dd mm yyyy): ";
            cin >> dob.dd >> dob.mm >> dob.yy;
            if ((dob.dd < 1 || dob.dd > 31) || (dob.mm < 1 || dob.mm > 12) || (dob.yy < 1000 || dob.yy > 2023)) {
                cout << "\nInvlaid Values for Date of Birth! Enter Again\n" << endl;
            }
            else {
                break;
            }
        } while (true);

        // individually validating DOA
        do {
            cout << "Enter Date of Admission (dd mm yyyy): ";
            cin >> doa.dd >> doa.mm >> doa.yy;
            if ((doa.dd < 1 || doa.dd > 31) || (doa.mm < 1 || doa.mm > 12) || (dob.yy < 1000 || dob.yy > 2023)) {
                cout << "\nInvalid Values for Date of Admission!\n" << endl;
            }
            else {
                break;
            }
        } while (true);

        if (dob.yy >= doa.yy) {
            cout << "\nDOA is less than DOB. Enter both dates again!\n" << endl;
        }
        else
            break;
    } while (true);

    // getting student marks
    for (int j = 0; j < MAXSUB; j++) {
        do {
            int tempMks = 0;
            cout << endl
                << "Enter Subject " << j + 1 << " marks: ";
            cin >> tempMks;
            cin.ignore(); // Add this line to clear newline character
            if (tempMks >= 0 && tempMks <= 100) {
                marks[j] = tempMks;
                totalMarks += tempMks;
                break;
            }
            else
                cout << "Invalid Marks. Enter marks between 0-100";
        } while (true);
    }

    prc = totalMarks / static_cast<double>(500) * 100;

    // Student In-Time and Out-Time
    do {
        cout << endl << "Student In-Time (24-hour format): ";
        inTime.setter();

        cout << "Student Out-Time (24-hour format): ";
        outTime.setter();
        if (outTime > inTime)
            break;
        else
            cout << "Student In time is less than Student Out Time!\nEnter the time again:";
    } while (true);

    cout << endl << "===================================================";
}
void student::getter() {
    cout << name.fname << " " << name.lname << "\t\t\t" << regno << "\t"
        << marks[0] << "\t" << marks[1] << "\t" << marks[2] << "\t" << marks[3]
        << "\t" << marks[4] << "\t" << totalMarks << "\t" << prc << "%" << endl;
}

// member functions for Updation Menu

int student::getRegNo() { return regno; }

void student::updateRegNo() {
    cout << "Enter new registration number for " << name.fname << " "
        << name.lname << ": ";
    cin >> regno;
    cout << endl;
}

void student::updateName() {
    cout << "Enter new name for " << name.fname << " " << name.lname << ": ";
    cout << endl << "Enter First Name (New): ";
    cin.ignore();
    getline(cin, name.fname);

    cout << endl << "Enter Last Name (New): ";
    getline(cin, name.lname);
    cout << endl;
}

void student::updateMarks() {
    totalMarks = 0;
    for (int j = 0; j < MAXSUB; j++) {
        do {
            int tempMks = 0;
            cout << endl << "Enter Subject " << j + 1 << " marks (new): ";
            cin >> tempMks;
            cin.ignore();
            if (tempMks >= 0 && tempMks <= 100) {
                marks[j] = tempMks;
                totalMarks += tempMks;
                break;
            }
            else
                cout << "Invalid Marks. Enter marks between 0-100";
        } while (true);
    }
    prc = totalMarks / static_cast<double>(500) * 100;
}

void student::updateDoa() {
    cout << "Enter date of Admission (New): ";
    cin.ignore();
    cin >> doa.dd >> doa.mm >> doa.yy;
    cout << endl;
}

void student::updateDob() {
    cout << "Enter date of Birth (New): ";
    cin.ignore();
    cin >> dob.dd >> dob.mm >> dob.yy;
    cout << endl;
}

void student::getStdBio() {
    cout << "First Name: " << name.fname << endl;
    cout << "Last Name: " << name.lname << endl;
    cout << "Date of Birth: " << dob.dd << "-" << dob.mm << "-" << dob.yy << endl;
    cout << "Date of Admission: " << doa.dd << "-" << doa.mm << "-" << doa.yy << endl;
    cout << "In-Time: ";
    inTime.getter();
    cout << "Out-Time: ";
    outTime.getter();
}

// End: Student Class Memeber Functions

// -------------------------------------------------------------------------------------//
// -------------------------------------------------------------------------------------//

// USER DEFINED FUNCTIONS

// Create new students records

void createDB(int& nn, student std[]) {
    cout << "Enter the number of students( <= 70 ): ";
    do {
        cin >> nn;
        if (nn > 0 && nn <= MAX) {
            break;
        }
        else {
            cout << "(Error! Enter number less than or equal to 70)" << endl
                << "\nEnter number of students again: ";
        }
    } while (true);
    cin.ignore(); // Add this line to clear newline character
    for (int i = 0; i < nn; i++) {
        cout << "Data for Student: " << i + 1 << endl;
        std[i].setter();
    }
}

// Show the result card of all students

void resultShow(student std[], int nn, int sPos) {
    cout << "Name\t"
        << "\t\t\tReg #\t"
        << "Subj 1\t"
        << "Subj 2\t"
        << "Subj 3\t"
        << "Subj 4\t"
        << "Subj 5\t"
        << "MKS OBT\t"
        << "Percentage" << endl
        << "--------------------------------------------------------------------"
        "--------------------------------------"
        << endl;
    if (sPos == -2) {
        for (int i = 0; i < nn; i++) {
            std[i].getter();
        }
    }
    else {
        if (sPos == -1)
            cout << "No Record found for this reg no!" << endl;
        else
            std[sPos].getter();
        sPos = -2;
    }
}

// Search from existing records

int searchRec(student std[], int nn) {
    int sInfo;
    int sPos = -1;

    cout << endl << "Enter reg no. of student: ";
    cin >> sInfo;
    for (int i = 0; i < nn; i++) {
        if (sInfo == std[i].getRegNo()) {
            sPos = i;
            break;
        }
    }
    return sPos;
}

// Delete from existing records

void delRecord(student std[], int& nn) {
    if (nn == 0)
        cout << endl << "No Data available. Please, insert some data." << endl;
    else {
        int delPos = searchRec(std, nn);
        if (delPos == -1)
            cout << endl << "Not Record found for Deletion" << endl;
        else {
            for (int i = delPos; i < nn - 1; i++) {
                std[i] = std[i + 1];
            }
            nn--;
            cout << endl << "Operation Successful!" << endl;
        }
    }
}

// showing Student Data update Form

void updateRecord(student std[], int nn) {

    char ch;

    int updatePos = searchRec(std, nn);

    if (updatePos == -1) {
        cout << "Record not found." << endl;
        return;
    }

    do {
        cout << endl
            << "----------------** Update Menu **----------------" << endl
            << "1. Update Student Registration No" << endl
            << "2. Update Student Name" << endl
            << "3. Update Student Subjects" << endl
            << "4. Update Student Admission Date" << endl
            << "5. Update Student Date of Birth" << endl
            << "6. Return to Previous Menu" << endl
            << "----------------** ----------- **----------------" << endl;

        cout << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch (ch) {
        case '1':
            std[updatePos].updateRegNo();
            break;
        case '2':
            std[updatePos].updateName();
            break;
        case '3':
            std[updatePos].updateMarks();
            break;
        case '4':
            std[updatePos].updateDoa();
            break;
        case '5':
            std[updatePos].updateDob();
            break;
        case '6':
            return;
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    } while (true);
}

// show student Bio Data

void showBio(student std[], int nn) {
    int userPos = searchRec(std, nn);
    if (userPos == -1)
        cout << "User does not exist";
    else
        std[userPos].getStdBio();
}
