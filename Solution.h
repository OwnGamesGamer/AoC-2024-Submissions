#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Program
{
    public:
    
    int safe = 0;
    bool isSafe(vector<int> list, bool Dampened);  
    bool ProblemDampener(vector<int> list, int index);

    void OpenFile();
    vector<int> Seperate(string line);



};
