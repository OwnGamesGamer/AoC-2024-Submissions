#include "Solution.h"

void printVector(vector<string> Vector){
    for (int i = 0; i < Vector.size(); i += 1){
        cout << Vector[i] << "  ";
    }
    cout << endl;

}

int findMiddle(vector<string> update){
    int i = (update.size()/2);
    return stoi(update[i]);
};

vector<string> ConvertUpdateToVector(string Update){
    vector<string> Vector = {};
    string tmp = "";

    for(int i = 0; i < Update.size(); i += 1){
        if (Update[i] == ','){
            Vector.push_back(tmp);
            tmp = "";
        } else tmp += Update[i]; 
    }
    Vector.push_back(tmp);

    return Vector;
}

int main(){
    Program myProgram("input");
    int Ans1 = 0;    
    int Ans2 = 0;    
    vector<string> Update;
    vector<string> CorUpdate;
    //int i = 0;
    for(int i = 0; i < myProgram.Updates.size() ; i+=1){
        Update = ConvertUpdateToVector(myProgram.Updates[i]);
        if (myProgram.CheckIfCorrect(Update)) {
            Ans1 += findMiddle(Update);
        } else{
            CorUpdate = myProgram.CorrectOrder(Update);
            cout << myProgram.CheckIfCorrect(CorUpdate) << endl;         
        
            Ans2 += findMiddle(CorUpdate);
        }
    }
    cout << "correct order updates are equal: " << Ans1 << endl;
    cout << "corrected order updates are equal: " << Ans2 << endl;
    return 0;
}


Program::Program(string FileName){
    ifstream file(FileName);
    string line;

    while(getline(file,line)){
        if (line != ""){
           seperateRules(line);
        } else {break;}
    }
    while(getline(file,line)){
        Updates.push_back(line);
    }

    file.close();
}

void Program::seperateRules(string line){
    string tmp = "";    
    for (int i = 0; i, i < line.size(); i += 1){
        if (line[i] == '|') {
            Rules1.push_back(tmp);
            tmp = "";
        } else {tmp += line[i];}
    }
    Rules2.push_back(tmp);
    return;
}

bool Program::CheckIfCorrect(vector<string> Update){

    for (int i = 0; i < Update.size(); i += 1){
        if (!CheckRules(Update[i], Update, i)) { return false; }
    }

    return true;
}

bool Program::CheckRules(string Page, vector<string> Update, int index){

    for(int i = 0; i < Rules1.size(); i += 1){
        if (Page == Rules1[i]){
            for (int j = 0; j < Update.size(); j += 1){
                if (Rules2[i] == Update[j]){
                    if(j < index){
                        return false;
                    } else {break;}
                }
            }    
        }
    }

    return true;
}

vector<string> Program::CorrectOrder(vector<string> Update){
    vector<string> CorUpdate = {};
    CorUpdate.push_back(Update[0]);
    int maxpos = 0;
    int minpos = 0;
    for(int i = 1; i < Update.size(); i += 1){
        maxpos = CorUpdate.size();
        minpos = 0;
        //cout << Update[i] << endl;

        for (int j = 0; j < Rules1.size(); j += 1){
            if(Rules1[j] == Update[i]){
               

                for(int k = 0; k < CorUpdate.size(); k += 1){
                    if (k < maxpos){                   
                        if (CorUpdate[k] == Rules2[j]){
                            maxpos = k;
                            //cout << Rules1[j] << "|" << Rules2[j] << endl;
                            //cout << k << endl;
                        }
                    } else {break;}                   
                }
                if (maxpos == 0) {break;}
            }
        }

        if(maxpos != 0){
            for (int j = 0; j < Rules2.size(); j += 1){
                if(Rules2[j] == Update[i]){

                    for(int k = 0; k < CorUpdate.size(); k += 1){
                        
                        if (minpos < maxpos){              
                            if (CorUpdate[k] == Rules1[j]){
                                minpos = k + 1;
                                //cout << Rules1[j] << "|" << Rules2[j] << endl;
                                //cout << k << endl;
                            }
                        }            
                    }
                    if (minpos == maxpos) {break;}
                }
            }
        }

        CorUpdate.emplace(CorUpdate.begin() + maxpos , Update[i]);
        //cout << maxpos << endl;
        //printVector(CorUpdate);

    }

    return CorUpdate;
}
