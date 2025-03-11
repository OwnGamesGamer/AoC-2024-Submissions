#include "Solution.h"

int Program::multiply(string line, int index){
    if (dont) return 0;
    string num = "";
    int num1;
    int num2;
    for(int i = index; i < line.size(); i += 1){
        if(isdigit(line[i])){
            num += line[i]; 
        } else if (line[i] == ','){
            if (num != ""){
                num1 = stoi(num);
                num = "";
            } else return 0;
        } else if (line[i] == ')'){
            if (num != ""){
                num2 = stoi(num);
                return num1 * num2;
            } else return 0;
        } else return 0;
    }
    return 0;
};

int main(){

    Program myProgram;
    myProgram.OpenFile();
    cout << "the sum of all the mul() is " << myProgram.sum << endl;
    return 0;
};

void Program::OpenFile(){

    ifstream file("input");
    string line;
    
    while (getline(file,line)){
    
        for(int i = 0; i < line.size(); i += 1){
            if(line[i] == 'm'){
                if (seeIfMul(line, i)){
                    sum += multiply(line, i+4);
                }
            } else if (line[i] == 'd'){
                seeIfDo(line, i);
            }
        }
        //dont = false;
    }
 
    return;
};

bool Program::seeIfMul(string line, int index){
    
    string tmp = "";
    tmp += line[index];
    
    for (int i = 1; i < 4 ; i += 1){
        tmp += line[index + i];
    }

    if (tmp != "mul(") return false;
    return true;
};

void Program::seeIfDo(string line, int index){
    string tmp = "";
    
    for (int i = index; i < index + 4 ; i += 1){
        tmp += line[i];
    }
    if (tmp == "do()") {
       dont = false;
       return;
    }
    for (int i = 4; i < 7 ; i += 1){
        tmp += line[index + i];
    }
    if (tmp == "don't()"){
        dont = true;
    }

    return;
};

