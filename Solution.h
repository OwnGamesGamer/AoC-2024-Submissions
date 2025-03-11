#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace  std;

class finder
{ public:
    string line;
    vector <int> list1;
    vector <int> list2;

    void Seperate(string line);
    void OpenFile();
    void SortLists();
    
    int CalcDis();
    int CalcScore();
};
