
#pragma
using namespace std;
class Parent  {
private:
    string fullName;
    string gender;
    string dob;
    string email;
    string contactNumber;
    string username;
    string password;
    string childFullName;

public:
    void registerUser(const string& filename) ;
    bool loginUser(const string& filename) ;
    void viewChildrenReports(const string& studentFile);
    void viewSchoolNotices(const string& noticeFile);    
};