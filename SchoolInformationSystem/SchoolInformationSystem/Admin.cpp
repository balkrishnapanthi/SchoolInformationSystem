#pragma
#include "Admin.h"
#include <vector>
#include <iostream>
#include "CSVFile.h"
using namespace std;

void Admin::accessClassRecords(const string& filename) {
    vector<vector<string>> classRecords = CSVFile::readData(filename);

    cout << "Class Records:\n";
    for (const auto& record : classRecords) {
        for (const auto& field : record) {
            cout << field << "\t";
        }
        cout << endl;
    }
}

void Admin::accessParentsRecords(const string& filename) {
    vector<vector<string>> parentRecords = CSVFile::readData(filename);

    cout << "Parents Records:\n";
    for (const auto& record : parentRecords) {
        for (const auto& field : record) {
            cout << field << "\t";
        }
        cout << endl;
    }
}

void Admin::generateReports(const string& teacherFile, const string& studentFile, const string& parentFile) {
    vector<vector<string>> teacherData = CSVFile::readData(teacherFile);
    vector<vector<string>> studentData = CSVFile::readData(studentFile);
    vector<vector<string>> parentData = CSVFile::readData(parentFile);

    cout << "Reports:\n";
    // Implement the logic to generate reports based on the data
}
