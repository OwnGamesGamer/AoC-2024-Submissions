#include <fstream>
#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Program
{
    public:
    
    Program(string FileName);

    //int breakindex;

    vector<string> Rules1 = {};
    vector<string> Rules2 = {};
    vector<string> Updates = {};
        

    void seperateRules(string line);
    bool CheckIfCorrect(vector<string> Update);
    bool CheckRules(string Page, vector<string> Update, int index);
    vector<string> CorrectOrder(vector<string> Update);
};
