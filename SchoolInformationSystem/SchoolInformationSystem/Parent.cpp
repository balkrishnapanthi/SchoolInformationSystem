#include <vector>
#include <string>
#include <iostream>
#include "Parent.h"
#include "CSVFile.h"

using namespace std;

void Parent::registerUser(const string& filename) {
    vector<vector<string>> parentData = CSVFile::readData(filename);

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

    cout << "Enter Child's Full Name: ";
    getline(cin, childFullName);

    vector<string> parentRecord = { fullName, gender, dob, email, contactNumber, username, password, childFullName };
    parentData.push_back(parentRecord);

    CSVFile::writeData(filename, parentData);

    cout << "Parent registration successful!\n";
}

bool Parent::loginUser(const string& filename) {
    vector<vector<string>> parentData = CSVFile::readData(filename);

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    for (const auto& record : parentData) {
        if (record[5] == username && record[6] == password) {
            cout << "Login successful!\n";
            childFullName = record[7];
            return true;
        }
    }

    cout << "Login failed. Incorrect username or password.\n";
    return false;
}

void Parent::viewChildrenReports(const string& studentFile) {
    vector<vector<string>> studentData = CSVFile::readData(studentFile);

    cout << "Your Child's Reports:\n";
    for (const auto& record : studentData) {
        if (record[0] == childFullName) {
            for (const auto& field : record) {
                cout << field << "\t";
            }
            cout << endl;
        }
    }
}

void Parent::viewSchoolNotices(const string& noticeFile) {
    vector<vector<string>> noticeData = CSVFile::readData(noticeFile);

    cout << "School Notices:\n";
    for (const auto& record : noticeData) {
        for (const auto& field : record) {
            cout << field << "\t";
        }
        cout << endl;
    }
}