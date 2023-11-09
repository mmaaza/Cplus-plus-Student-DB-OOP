// Program: Student Database using Array of Objects
// Programmer: Muhammad Maaz Ahmad
// Compiler: Microsoft Visual Studio 2022 Community Edition

#include <iostream>
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

class stdTime {
    unsigned int hour;
    unsigned int min;
    unsigned int sec;

public:
    void getter();
    void setter();

    stdTime() {
        hour = min = sec = 0;
    }
};

class student {
    int regno;
    nameType name;
    int marks[MAXSUB];
    int totalMarks;
    double gpa, prc;
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

    void setter(int i);
    void getter();
    void appendRec(int nn);
    int getRegNo();
    void updateRegNo();
    void updateName();
    void updateMarks();
    void updateDoa();
    void updateDob();
    void getStdBio();

    stdTime inTime;
    stdTime outTime;
};

// Start: Nested Class Member Functions 

void stdTime::setter() {
    cout << "Enter the time (h m s): ";
    cin >> hour >> min >> sec;
    cout << endl;
}

void stdTime::getter() {
    cout << hour << ":" << min << ":" << sec << endl;
}

// End: Nested Class Member Functions

// Start: Outer Class Memeber Functions

void student::setter(int i) {
    cout << endl << "Enter student " << i + 1 << " registration number: ";
    cin >> regno;

    cout << endl << "Enter student " << i + 1 << " First Name: ";
    cin.ignore(); // to ignore newline character left in the buffer by cin
    getline(cin, name.fname);

    cout << endl << "Enter student " << i + 1 << " Last Name: ";
    getline(cin, name.lname);

    cout << endl << "Enter student " << i + 1 << " Date of Birth (dd mm yyyy): ";
    cin >> dob.dd >> dob.mm >> dob.yy;

    cout << endl
        << "Enter student " << i + 1 << " Date of Admission (dd mm yyyy): ";
    cin >> doa.dd >> doa.mm >> doa.yy;

    for (int j = 0; j < MAXSUB; j++) {
        do {
            int tempMks = 0;
            cout << endl
                << "Enter student " << i + 1 << " Subject " << j + 1 << " marks: ";
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
    cout << endl << "Student In-Time:" << endl;
    inTime.setter();

    cout << "Student Out-Time:" << endl;
    outTime.setter();

    cout << endl << "===================================================";
}
void student::getter() {
    cout << name.fname << " " << name.lname << "\t\t\t" << regno << "\t"
        << marks[0] << "\t" << marks[1] << "\t" << marks[2] << "\t" << marks[3]
        << "\t" << marks[4] << "\t" << totalMarks << "\t" << prc << "%" << endl;
}

void student::appendRec(int nn) {
    totalMarks = 0;
    cout << endl << "Enter student " << nn + 1 << " registration number: ";
    cin >> regno;
    cout << endl << "Enter student " << nn + 1 << " First Name: ";
    cin.ignore();
    getline(cin, name.fname);

    cout << endl << "Enter student " << nn + 1 << " Last Name: ";
    getline(cin, name.lname);

    cout << endl << "Enter student " << nn + 1 << " Date of Birth (dd mm yyyy): ";
    cin >> dob.dd >> dob.mm >> dob.yy;

    cout << endl
        << "Enter student " << nn + 1 << " Date of Admission (dd mm yyyy): ";
    cin >> doa.dd >> doa.mm >> doa.yy;

    for (int j = 0; j < MAXSUB; j++) {
        do {
            int tempMks = 0;
            cout << endl
                << "Enter student " << nn + 1 << " Subject " << j + 1 << " marks: ";
            cin >> tempMks;
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
    cout << endl << "Student In-Time:" << endl;
    inTime.setter();

    cout << "Student Out-Time:" << endl;
    outTime.setter();

    cout << endl << "===================================================";
}

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

// End: Outer Class Memeber Functions

// -------------------------------------------------------------------------------------//
// -------------------------------------------------------------------------------------//

// Create new students records

void createDB(int& nn, student std[]) {
    cout << "Enter the number of students( <70 ): ";
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
        std[i].setter(i);
    }
}

// Show the result card of all students

void resultShow(student std[], int nn, int sPos = -2) {
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
        cout << "User doesnot exist";
    else
        std[userPos].getStdBio();
}

int main() {
    student std[MAX];
    int n = 0;
    char ch;
    do {
        cout << endl
            << "----------------** Menu **----------------" << endl
            << "1. Add or Append Data" << endl
            << "2. Display Result Card" << endl
            << "3. Search a particular Record" << endl
            << "4. Delete a Record" << endl
            << "5. Update Record" << endl
            << "6. Students Bio" << endl
            << "7. Exit" << endl
            << "----------------** ---- **----------------" << endl;

        cout << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch (ch) {
        case '1':
            if (n > 0) {
                std[n].appendRec(n);
                n++;
            }
            else
                createDB(n, std);
            break;
        case '2':
            if (n > 0)
                resultShow(std, n);
            else
                cout << "No records found! Please enter some data first.";
            break;
        case '3':
            if (n > 0) {
                int sRes = searchRec(std, n);
                resultShow(std, n, sRes);
            }
            else
                cout << "No records found! Please enter some data first.";
            break;
        case '4':
            if (n > 0)
                delRecord(std, n);
            else
                cout << "No records found! Please enter some data first.";
            break;
            break;
        case '5':
            if (n > 0)
                updateRecord(std, n);
            else
                cout << "No records found! Please enter some data first.";
            break;
        case '6':
            if (n > 0)
                showBio(std, n);
            else
                cout << "No records found! Please enter some data first.";
            break;
        case '7':
            exit(-1);
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    } while (true);
    return 0;
}
