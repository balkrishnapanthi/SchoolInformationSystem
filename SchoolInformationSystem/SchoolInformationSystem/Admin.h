#pragma
#include "User.h"
#include <string> 
using namespace std; 

class Admin  {
public:
    void accessClassRecords(const string& filename);
    void accessParentsRecords(const string& filename);
    void generateReports(const string& teacherFile, const string& studentFile, const string& parentFile);
};