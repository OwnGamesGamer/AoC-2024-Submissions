#include "Solution.h"


int FindInVector(vector <int> Vector, int val){
    bool found = 0;
    int i = 0;
    for (i = 0; i < Vector.size() && !found; i += 1){
        if (Vector[i] == val){
            found = 1;        
        }
    }
    if (found){
        return i - 1;
    }
    return -1;
};

int FindHowMany(vector<int> Vector, int val, int index){
    int amount;
    bool found = 0;
    for (amount = index; amount < Vector.size() && !found; amount += 1){
        if (Vector[amount] != val){
            found = 1;        
        }
    }

    return amount - index - 1;
}

vector <int> sort(vector <int> list){
    vector <int> tmp;
    bool found = false;
    int num;
    tmp.push_back(list[0]);
    for (int i = 1; i< list.size(); i += 1){
        num = list[i];
        found = 0;
        for (int j = 0; j<tmp.size() && !found; j += 1){
            if (num < tmp[j]){
                tmp.emplace(tmp.begin()+j, num);
                found = 1;
            }   
        }
        if (!found) {
            tmp.push_back(num);        
        }
    }
    return tmp;
};

void printVector(vector <int> myVector){
    for (int i = 0; i < myVector.size(); i += 1){
        cout << myVector[i] << endl;    
    };
};

int main(){
    finder myFinder;
    myFinder.OpenFile();
    myFinder.SortLists();

    cout << "distance: " ;
    cout << myFinder.CalcDis() << endl;
    cout << "Similarity score: " ;
    cout << myFinder.CalcScore() << endl;
    
    return 0;
};

void finder::OpenFile() {
   
    ifstream file("input");

    if (file.is_open()){
        while (getline(file, line)){
            Seperate(line);
        }    
    }    
    file.close(); 
    return ;
};

void finder::Seperate(string line){
    string FirstID = "";
    string SecondID = "";
    for(int i = 0; i < 5; i += 1){
        FirstID += line[i];
        SecondID += line[i+8];
    }
    list1.push_back(stoi(FirstID));
    list2.push_back(stoi(SecondID));
    return;
};


void finder::SortLists(){
    list1 = sort(list1);
    list2 = sort(list2);
    return;
}

int finder::CalcDis(){
    int distance = 0;
    for (int i = 0; i < list1.size(); i += 1){
        distance += abs(list1[i] - list2[i]);
    }
    return distance;
};

int finder::CalcScore(){
    int Score = 0;
    int tmp;
    int index;
    for (int i = 0; i < list1.size(); i += 1){
        tmp = list1[i];
        index = FindInVector(list2, tmp);
        if (index >= 0){
            Score += FindHowMany(list2, tmp, index) * tmp;
        }
    }
    return Score;
};
