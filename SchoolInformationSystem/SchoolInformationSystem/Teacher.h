#pragma

#include <string>



class Teacher {
private:
    string fullName;
    string gender;
    string dob;
    string email;
    string contactNumber;
    string username;
    string password;
    string classroomNumber;
    string yearTeach;

public:
    void registerUser(const string& filename) ;
    bool loginUser(const string& filename) ;
    void createStudentRecord(const string& filename);   
};