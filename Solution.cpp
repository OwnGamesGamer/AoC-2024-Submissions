#include "Solution.h"

void printVector(vector<long long int> Vector){
    for (int i = 0; i < Vector.size(); i += 1){
        cout << Vector[i] << "  " ;
    }
    cout << endl << endl;
}

unsigned long int combine_ints(unsigned long int a, unsigned long int b){
    string tmp = to_string(a) + to_string(b);

    return stoul(tmp);
}
vector<unsigned long long int> ConvertAccordTripset(vector <unsigned long long int> numbers, string tripset){
    vector <unsigned long long int> tmp;
    for (int i = 1; i < numbers.size()-1; i += 1){
        //cout << i << " of " << numbers.size() << endl;
        if(tripset[i-1] == '2'){
            tmp.push_back(combine_ints(numbers[i], numbers[i+1]));

            i += 1;
        } else tmp.push_back(numbers[i]); 
    }
    return tmp;
}

string int_to_tripset(unsigned long int input){
    string tmp = "";
    unsigned long int tmpint = input;

    for(int i = 0; tmpint != 0; i += 1){
        tmp += to_string(tmpint % 3); 
        tmpint /= 3;
    }
    tmp += "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    //cout << tmp << endl << endl;
    return tmp;
}

unsigned long long int CheckIfCorrect(vector<unsigned long long int> numbers){
    unsigned long long int tmp;
    vector<unsigned long long int> Vector;
    unsigned long int ways = pow(3,numbers.size()-2);
    string tripset;    
    int offset;

    for (unsigned long int i = 0; i < ways; i += 1){
        tripset = int_to_tripset(i);
        Vector = ConvertAccordTripset(numbers, tripset);
        tmp = numbers[1];
        offset = -2;
        for (int j = 2; j < Vector.size(); j += 1){
            while(tripset[j+offset] == '2'){
                offset += 1;
            }
            if(tripset[j+offset] == '1'){
                tmp *= Vector[j];
            } else {
                tmp += Vector[j];
            }
        }
        
        if (tmp == Vector[0]) {
            return tmp;
        }
    }


    return 0;
}

int main(){
    Program myProgram("input");

    myProgram.CheckLines();
    cout << "sum : " << myProgram.sum << endl;
    return 0;
}

Program::Program(string name){
    ifstream myFile{name};
    string line;
    
    while(getline(myFile, line)){
        lines.push_back(line);
    }
    
    myFile.close();
}

void Program::CheckLines(){
    string tmp;    
    vector<unsigned long long int> numbers;
  
    for(int i = 0; i < lines.size(); i += 1){
        tmp = "";
        numbers = {};
        for(int j = 0; j < lines[i].size(); j += 1){
            if(lines[i][j] == ':' || lines[i][j] == ' '){
                if(tmp != "") {
                    numbers.push_back(stoull(tmp));                    
                }
                tmp = "";
            } else {tmp += lines[i][j];}
        }
        
        numbers.push_back(stoull(tmp)); 
        //printVector(numbers);
        sum += CheckIfCorrect(numbers); 
   
    }
    
    
    return;
}
