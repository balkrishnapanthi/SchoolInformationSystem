#pragma
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "CSVFile.h"
#include "Teacher.h"
using namespace std;
void Teacher::registerUser(const string& filename) {
    vector<vector<string>> teacherData = CSVFile::readData(filename);

    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, fullName);

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    getline(cin, dob);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter Contact Number: ";
    getline(cin, contactNumber);

    cout << "Enter Username: ";
    getline(cin, username);

    cout << "Enter Password: ";
    getline(cin, password);

    cout << "Enter Classroom Number: ";
    getline(cin, classroomNumber);

    cout << "Enter Year Teach (e.g., Year 1): ";
    getline(cin, yearTeach);

    vector<string> teacherRecord = { fullName, gender, dob, email, contactNumber, username, password, classroomNumber, yearTeach };
    teacherData.push_back(teacherRecord);

    CSVFile::writeData(filename, teacherData);

    cout << "Teacher registration successful!\n";
}

bool Teacher::loginUser(const string& filename) {
    vector<vector<string>> teacherData = CSVFile::readData(filename);

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    for (const auto& record : teacherData) {
        if (record[5] == username && record[6] == password) {
            cout << "Login successful!\n";
            return true;
        }
    }

    cout << "Login failed. Incorrect username or password.\n";
    return false;
}

void Teacher::createStudentRecord(const string& filename) {
    vector<vector<string>> studentData = CSVFile::readData(filename);

    cout << "Enter Student Full Name: ";
    cin.ignore();
    getline(cin, fullName);

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Maths Grade: ";
    getline(cin, dob);

    cout << "Enter Science Grade: ";
    getline(cin, email);

    cout << "Enter Writing Grade: ";
    getline(cin, contactNumber);

    cout << "Enter Reading Grade: ";
    getline(cin, username);

    cout << "Enter Other Grade (e.g., sports, art, music, etc.): ";
    getline(cin, password);

    cout << "Enter Learning Progress (Achieved, Progressing, Need Help): ";
    getline(cin, classroomNumber);

    vector<string> studentRecord = { fullName, gender, dob, email, contactNumber, username, password, classroomNumber };
    studentData.push_back(studentRecord);

    CSVFile::writeData(filename, studentData);

    cout << "Student record created!\n";
}
