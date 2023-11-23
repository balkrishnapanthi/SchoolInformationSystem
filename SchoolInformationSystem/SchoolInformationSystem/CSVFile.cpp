#pragma
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include "CSVFile.h"

using namespace std;



void CSVFile::writeData(const string& filename, const vector<vector<string>>& data) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto& row : data) {
        for (const auto& col : row) {
            file << col << ",";
        }
        file << "\n";
    }

    file.close();
}

vector<vector<string>> CSVFile::readData(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return data;
    }

    string line, cell;
    while (getline(file, line)) {
        stringstream lineStream(line);
        vector<string> row;
        while (getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    file.close();
    return data;
}

