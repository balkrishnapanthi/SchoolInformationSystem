#pragma
#include <string>
using namespace std;
class StudentRecord {
private:
    string className;
    string fullName;
    string gender;
    string maths;
    string science;
    string writing;
    string reading;
    string others;
    string learningProgress;

public:
    void addStudent(const string& filename);
    void editStudentRecord(const string& filename);
    void deleteStudentRecord(const string& filename);
    void updateRecord(const string& filename);
    void viewRecords(const string& filename);
};