#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
class Crud {
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    // Function to display the menu
    void displayMenu() {
        cout << "1. Create user\n";
        cout << "2. Read users\n";
        cout << "3. Update user\n";
        cout << "4. Delete user\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
    }

    // Function to create a new user record
    void createUser(std :: fstream& file) {
        string name, age, email;
        cout << "Enter user details:\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Age: ";
        getline(cin, age);
        cout << "Email: ";
        getline(cin, email);

        file << name << "," << age << "," << email << "\n";
        cout << "User created successfully.\n";
    }

    // Function to read and display all user records
    void readUsers(fstream& file) {
        cout << "List of users:\n";
        string line;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            cout << "Name: " << tokens[0] << ", Age: " << tokens[1] << ", Email: " << tokens[2] << "\n";
        }
    }

    // Function to update a user record
    void updateUser(fstream& file) {
        string name, age, email;
        string newName, newAge, newEmail;
        cout << "Enter the details of the user to update:\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        string line;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == name) {
                found = true;
                cout << "Enter new details:\n";
                cout << "New Name: ";
                getline(cin, newName);
                cout << "New Age: ";
                getline(cin, newAge);
                cout << "New Email: ";
                getline(cin, newEmail);

                file.seekp(file.tellg() - streamoff(line.length() + 1)); // Move the file pointer back to the beginning of the current line
                file << newName << "," << newAge << "," << newEmail << "\n";
                cout << "User updated successfully.\n";
                break;
            }
        }

        if (!found) {
            cout << "User not found.\n";
        }
    }

    // Function to delete a user record
    void deleteUser(fstream& file) {
        string name;
        cout << "Enter the name of the user to delete: ";
        cin.ignore();
        getline(cin, name);

        ofstream tempFile("temp.csv"); // Create a temporary file
        bool found = false;
        string line;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == name) {
                found = true;
                cout << "User deleted successfully.\n";
            }
            else {
                tempFile << line << "\n";
            }
        }

        file.close();
        tempFile.close();
        remove("users.csv"); // Remove the original file
        rename("temp.csv", "users.csv"); // Rename the temporary file to the original file name

        if (!found) {
            cout << "User not found.\n";
        }
    }

    public :
    int RunCrud() {
        //fstream file("users.csv", ios::in | ios::out | ios::app);

       

        int choice;
        do {
            displayMenu();
            cin >> choice;
            fstream file("users.csv", ios::in | ios::out | ios::app);
            if (!file.is_open()) {
                cerr << "Error opening file.\n";
                return 1;
            }
            switch (choice) {
            case 1:
                createUser(file);
                break;
            case 2:
                file.seekg(0); // Move the file pointer to the beginning of the file
                readUsers(file);
                file.close();
                break;
            case 3:
                file.seekg(0);
                updateUser(file);
                break;
            case 4:
                file.seekg(0);
                deleteUser(file);
                //file.open("users.csv", ios::in | ios::out | ios::app); // Reopen the file after deletion
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                file.close();
            }
        } while (choice != 5);

        //file.close();

        return 0;
    }

};