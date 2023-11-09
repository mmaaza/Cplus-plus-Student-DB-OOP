// Program: Student Database using Array of Objects
// Programmer: Muhammad Maaz Ahmad
// Compiler: Microsoft Visual Studio 2022 Community Edition

#include <iostream>
#include "student.h"


int main() {
    student std[MAX];
    int n = 0;
    char ch;
    do {
        // program menu
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
            // Append a New student
            if (n > 0) {
                std[n].setter();
                n++;
            }
            else
                // Add New students
                createDB(n, std);
            break;
        case '2':
            // show all students result
            if (n > 0)
                resultShow(std, n);
            else
                cout << "No records found! Please enter some data first.";
            break;
        case '3':
            // search specific student and get back the index
            if (n > 0) {
                int sRes = searchRec(std, n);
                resultShow(std, n, sRes);
            }
            else
                cout << "No records found! Please enter some data first.";
            break;
        case '4':
            // delete specific student record
            if (n > 0)
                delRecord(std, n);
            else
                cout << "No records found! Please enter some data first.";
            break;
            break;
        case '5':
            // update student record
            if (n > 0)
                updateRecord(std, n);
            else
                cout << "No records found! Please enter some data first.";
            break;
        case '6':
            // show student Bio
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
