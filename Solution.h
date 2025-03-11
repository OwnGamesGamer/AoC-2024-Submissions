#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Program{
    public:
    Program(string name);
    
    unsigned long long int sum = 0;    

    vector<string> lines {};

    void CheckLines();
};
