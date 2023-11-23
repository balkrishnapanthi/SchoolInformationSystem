
#pragma
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Admin.h"
#include "Student.h"

#include "Teacher.h"
#include "Parent.h"

using namespace std;

int main() {
    const string teacherFile = "teacher_data.csv";
    const string studentFile = "student_data.csv";
    const string parentFile = "parent_data.csv";
    const string noticeFile = "school_notices.csv";

    while (true) {
        cout << "Select User Type:\n1. Teacher\n2. Admin\n3. Parent\n4. Exit\n";
        int userType;
        cin >> userType;

        switch (userType) {
        case 1: {
            Teacher teacher;
            cout << "1. Register\n2. Login\n3. Create Student Record\n";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                teacher.registerUser(teacherFile);
                break;
            case 2:
                teacher.loginUser(teacherFile);
                break;
            case 3:
                teacher.createStudentRecord(studentFile);
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
            break;
        }
        case 2: {
            Admin admin;
            cout << "1. Access Class Records\n2. Access Parents Records\n3. Generate Reports\n";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                admin.accessClassRecords(studentFile);
                break;
            case 2:
                admin.accessParentsRecords(parentFile);
                break;
            case 3:
                admin.generateReports(teacherFile, studentFile, parentFile);
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
            break;
        }
        case 3: {
            Parent parent;
            cout << "1. Register\n2. Login\n3. View Children Reports\n4. View School Notices\n";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                parent.registerUser(parentFile);
                break;
            case 2:
                parent.loginUser(parentFile);
                break;
            case 3:
            {
                Parent parent1;
                parent1.loginUser(parentFile);
                parent1.viewChildrenReports(studentFile);
                break;
            }
              
            case 4:
                parent.viewSchoolNotices(noticeFile);
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
            break;
        }
        case 4:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid user type\n";
            break;
        }
    }

    return 0;
}
