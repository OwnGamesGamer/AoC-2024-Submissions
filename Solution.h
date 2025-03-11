#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Program
{
    public :
    int sum = 0;

    bool dont = false;
    void OpenFile();
    bool seeIfMul(string line, int index);
    void seeIfDo(string line, int index);
    int multiply(string line, int index);
};
