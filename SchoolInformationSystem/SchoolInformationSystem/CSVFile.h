#pragma
#include <string>
using namespace std;
class CSVFile {
public:
    static void writeData(const string& filename, const vector<vector<string>>& data);
    static vector<vector<string>> readData(const string& filename);
};