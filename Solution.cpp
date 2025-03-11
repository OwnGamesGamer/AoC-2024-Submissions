#include "Solution.h"

int findHorizontal (string line){
    string tmp1 = "X";  
    string tmp2 = "X";
    int found = 0;

    for (int i = 0; i < line.size(); i += 1){
        if (line[i] == 'X'){
            for (int j = 1; j < 4; j += 1){
                if(i+j <= line.size()) tmp1 += line[i+j];
                if(i-j >= 0) tmp2 += line[i-j];
            }
            if (tmp1 == "XMAS") found += 1;
            if (tmp2 == "XMAS") found += 1;
            tmp1 = "X";
            tmp2 = "X";
        }
    }
    return found;
};

int findVertical(vector<string> lines){
    int found = 0;
    string tmp = "X";

    for (int i = 0; i < lines[0].size(); i += 1){
        if (lines[0][i] == 'X'){
            tmp += lines[1][i];
            tmp += lines[2][i];
            tmp += lines[3][i];
        }else if (lines[3][i] == 'X'){
            tmp += lines[2][i];
            tmp += lines[1][i];
            tmp += lines[0][i];
        }
        if (tmp == "XMAS") found += 1;
        tmp = "X";
    };

    return found;
};

int findDiagnal(vector<string> lines){
    int found = 0;
    string tmp1 = "X";
    string tmp2 = "X";
    string tmp3 = "X";
    string tmp4 = "X";
     for (int i = 0; i < lines[0].size(); i += 1){
        if (lines[0][i] == 'X'){
            if (i+3 <= lines[0].size()){
                tmp1 += lines[1][i+1];
                tmp1 += lines[2][i+2];
                tmp1 += lines[3][i+3];
            }
            if (i-3 >= 0){
                tmp2 += lines[1][i-1];
                tmp2 += lines[2][i-2];
                tmp2 += lines[3][i-3];
            }
        }
        if (lines[3][i] == 'X'){
            if (i+3 <= lines[0].size()){
                tmp3 += lines[2][i+1];
                tmp3 += lines[1][i+2];
                tmp3 += lines[0][i+3];
            }
            if (i-3 >= 0){
                tmp4 += lines[2][i-1];
                tmp4 += lines[1][i-2];
                tmp4 += lines[0][i-3];
            }
        }
        if (tmp1 == "XMAS") found += 1;
        if (tmp2 == "XMAS") found += 1;
        if (tmp3 == "XMAS") found += 1;
        if (tmp4 == "XMAS") found += 1;
        tmp1 = "X";
        tmp2 = "X";
        tmp3 = "X";
        tmp4 = "X";
    };
    return found;
}

int findxmases(vector<string> lines){
    int found = 0;
    string tmp1 = "";
    string tmp2 = "";
    int mases = 0;
    
    for (int i = 1; i < lines[1].size()-1; i += 1){
        if(lines[1][i] == 'A'){
            tmp1 += lines[0][i-1];
            tmp2 += lines[2][i-1];
            tmp1 += "A";
            tmp2 += "A";
            tmp1 += lines[2][i+1];
            tmp2 += lines[0][i+1];
                        
            if (tmp1 == "MAS" || tmp1 == "SAM") mases += 1;
            if (tmp2 == "MAS" || tmp2 == "SAM") mases += 1;
            if (mases == 2) found += 1;
            
            mases = 0;
            tmp1 = "";
            tmp2 = "";
        }
    }
    return found;
}

int main() {
    Program myProgram;
    myProgram.openFile();


    cout <<"there are: "<< myProgram.xmases << " xmas-es" << endl;
    cout <<"there are: "<< myProgram.xmasses << " x-mas-es" << endl;
    return 0;
}


void Program::openFile(){
    ifstream myfile("input");
    string line;
    vector <string> lines = {};
    vector <string> lines2 = {};

    while(getline(myfile, line)){
        xmases += findHorizontal(line);
        if (lines.size() >= 3) {
            lines.push_back(line);
            xmases += findVertical(lines);
            xmases += findDiagnal(lines);
            lines.erase(lines.begin());
        } else {
             lines.push_back(line);
        }

        if (lines2.size() >= 2) {
            lines2.push_back(line);
            xmasses += findxmases(lines2);
            lines2.erase(lines2.begin());
        } else {
             lines2.push_back(line);
        }

    }
    myfile.close();
    return;
};
