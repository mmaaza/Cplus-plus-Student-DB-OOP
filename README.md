# C++: Student Database using Structures and OOPA
Student Database using Structures (Nested) and Object Oriented Programming Approach OOPA

This program contains the following files:<br>
**student.h:** Contains the "student" class and its member function prototypes. Also contains prototypes of user defined functions. <br>
**student.cpp:** Contains the definitions of member function and user defined functions. <br>
**main.cpp:** Contains the front end layer of the program. <br>
<br>
This program contains the following functions:<br>
#### readData():
gets the number of students, data of each student and put them in the array.<br/>
#### appendData():
appends data next to the last record.<br/>
#### resultGen():
processes the data and generates the result.<br/>
#### resultShow():
shows the result of all the students in the form of the table.<br/>
#### searchRec():
gets the registration number from the user and search it in the array. if found, then returns the index of it in the array otherwise displays message that record not found.<br/>
#### delRecord():
utilizes the **searchRec()** function and deletes the specific index by overwriting the data to one prior position.<br/>
#### main():
tester for all the things
<br>
<br>

**Program also contains the updation Menu** <br>
First of all, the user enters the registration number of the student. Then if available, following operations can be performed<br>
#### updateRecord():
updateRec() shows the updation menu and calls all the updation functions.<br/>
#### updateRegNo():
updates registration number of the student.<br/>
#### updateName():
updates name of the student.<br/>
#### updateMarks():
updates subject marks of the student.<br/>
#### updateDob():
updates date of birth of the student.<br/>
#### updateDoa():
updates date of admission of the student.<br/>
