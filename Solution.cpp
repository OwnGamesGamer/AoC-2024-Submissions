#include "Solution.h"

void printVector(vector <int> myVector){
    for (int i = 0; i < myVector.size(); i += 1){
        cout << myVector[i] << "  ";    
    };
    cout << endl;
};


bool Program::ProblemDampener(vector<int> list, int index){
    vector<int> tmp = {};
    for(int i = 0; i < list.size(); i += 1){
        if(i != index){
            tmp.push_back(list[i]);
        }
    }
   if (index == -1) return false;
   if (isSafe(tmp, true)){
        return true;        
   } else return ProblemDampener(list, index-1);
   
}; 

bool Program::isSafe(vector<int> list, bool Dampened){
    int rise = 0;
    int diff;
    bool wrong = 0;

    for (int i = 1; i < list.size(); i += 1){
        diff = list[i-1] - list[i];
        if (abs(diff) > 3 || diff == 0) wrong = 1;
        if (diff < 0) {
            rise += 1;        
        }else rise -= 1;
    
        if(abs(rise) != i) wrong = 1;
        if (wrong && !Dampened){
           return ProblemDampener(list, list.size());
        } 
        if (wrong && Dampened) return false;
    }
    return true;
};


int main() {
    
    Program myProgram;
    
    //vector<int> TestList = {1 ,4 ,4 ,6 ,7};    
    //ProblemDampener(TestList, 2);
    
    myProgram.OpenFile();
    cout << "There are " << myProgram.safe << " safe reports" << endl;

    return 0;
};


void Program::OpenFile() {
   
    ifstream file("input");
    string line;
    vector<int> numbers;
    vector<int> Diferences;

    if (file.is_open()){

        while (getline(file, line)){
            numbers = Seperate(line);
            if( isSafe(numbers, false)){ 
                safe += 1; 
            };
        }    
    }    
    file.close(); 
    return;
};

vector<int> Program::Seperate(string line){
    vector <int> numbers = {};
    string tmp = "";

    for(int i = 0; i < line.size(); i += 1){
        if(line[i] == ' '){
            numbers.push_back(stoi(tmp));
            tmp = "";
        }
        else tmp += line[i];
    }
    numbers.push_back(stoi(tmp));
    return numbers;
};
