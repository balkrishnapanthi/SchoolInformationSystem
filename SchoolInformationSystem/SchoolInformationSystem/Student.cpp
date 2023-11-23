#pragma
#include <vector>
#include <string>
#include <iostream>
#include "Student.h"
#include "CSVFile.h"
#include "User.h"
using namespace std;

void StudentRecord::addStudent(const string& filename) {
    vector<vector<string>> studentData = CSVFile::readData(filename);

    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, fullName);

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Maths Grade: ";
    getline(cin, maths);

    cout << "Enter Science Grade: ";
    getline(cin, science);

    cout << "Enter Writing Grade: ";
    getline(cin, writing);

    cout << "Enter Reading Grade: ";
    getline(cin, reading);

    cout << "Enter Other Grade (e.g., sports, art, music, etc.): ";
    getline(cin, others);

    cout << "Enter Learning Progress (Achieved, Progressing, Need Help): ";
    getline(cin, learningProgress);

    vector<string> studentRecord = { fullName, gender, maths, science, writing, reading, others, learningProgress };
    studentData.push_back(studentRecord);

    CSVFile::writeData(filename, studentData);

    cout << "Student record added!\n";
}

void StudentRecord::editStudentRecord(const string& filename) {
    vector<vector<string>> studentData = CSVFile::readData(filename);

    cout << "Enter Full Name of the Student to Edit: ";
    cin.ignore();
    getline(cin, fullName);

    // Search for the student record and edit the data

    CSVFile::writeData(filename, studentData);

    cout << "Student record edited!\n";
}

void StudentRecord::deleteStudentRecord(const string& filename) {
    vector<vector<string>> studentData = CSVFile::readData(filename);

    cout << "Enter Full Name of the Student to Delete: ";
    cin.ignore();
    getline(cin, fullName);

    // Search for the student record and delete it

    CSVFile::writeData(filename, studentData);

    cout << "Student record deleted!\n";
}

void StudentRecord::updateRecord(const string& filename) {
    vector<vector<string>> studentData = CSVFile::readData(filename);

    cout << "Enter Full Name of the Student to Update: ";
    cin.ignore();
    getline(cin, fullName);

    // Search for the student record and update the data

    CSVFile::writeData(filename, studentData);

    cout << "Student record updated!\n";
}

void StudentRecord::viewRecords(const string& filename) {
    vector<vector<string>> studentData = CSVFile::readData(filename);

    cout << "Student Records:\n";
    for (const auto& record : studentData) {
        for (const auto& field : record) {
            cout << field << "\t";
        }
        cout << endl;
    }
}