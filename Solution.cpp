#include "Solution.h"

void printVector(vector<string> line){
    for(int i = 0; i < line.size(); i += 1){
        cout << line[i] << endl;
    }
    cout << endl << endl;
}


int main(){
    Map myMap("input");
    int loops = 0;
    //myMap.locX = myMap.X;
    //myMap.locY = myMap.Y;
    while(myMap.out != true){
        myMap.moveGuard(true);
        //printVector(myMap.mapVector);
        //cout << endl << endl;
    }
    //printVector2(myMap.LocYsave);
    //cout <<myMap.LocXsave.size() << endl;
    cout << "She visited: " << myMap.spaces << " different spaces!" << endl;
    for(int i = 1; i < myMap.LocXsave.size(); i += 1){
        myMap.mapVector = myMap.mapVectorOri;
        myMap.mapVector[myMap.LocXsave[i]][myMap.LocYsave[i]] = 'O';
        myMap.out = false;
        myMap.loop = false;
        myMap.locX = myMap.LocXsave[i-1];
        myMap.locY = myMap.LocYsave[i-1];
        myMap.Direction = myMap.LocRotsave[i-1];
        myMap.RotDirSave = {};
        myMap.RotXsave = {};
        myMap.RotYsave = {};
        
        while(!myMap.out){
            myMap.moveGuard(false);
        }
        
        if(myMap.loop) {
            loops += 1;
        }
        
    }

    
    cout << "there are: " << loops << " different ways to make a loop!" << endl;
    return 0;
}

Map::Map(string mapName){
    ifstream mapFile(mapName);
    string line;
    int i = 0;

    while(getline(mapFile,line)){
        mapVector.push_back(line);
        if(line.find_first_of("^") != string::npos){
            locX = i;        
            for(int j = 0; j < line.size(); j += 1){
                if(line[j] == '^'){
                    locY = j;
                    break;
                }
            }    
        }
        i += 1;
    }
    //cout << mapVector[GuardCords[1]][GuardCords[0]] << endl;
    LocXsave.push_back(locX);
    LocYsave.push_back(locY);
    LocRotsave.push_back(Dir::up);
    mapVectorOri = mapVector;
    mapFile.close();
    return;
}

void Map::moveGuard(bool First){
    mapVector[locX][locY] = 'X';
    switch (Direction)
    {
        case Dir::up:
            moveUp(First);
            break;
        case Dir::right:
            moveRight(First);
            break;
        case Dir::down:
            moveDown(First);
            break;
        case Dir::left:
            moveLeft(First);
            break;
    }
    if(out) { return ;}    



    if(mapVector[locX][locY] != 'X'){
        spaces += 1;
        if(First){
            LocXsave.push_back(locX);
            LocYsave.push_back(locY);
            LocRotsave.push_back(Direction);
        }
        //spacesReRow = 0;
    } //else { spacesReRow += 1; }

    return;
}

void Map::moveUp(bool First){
    if(locX  == 0) {
        out = true;
        return;
    }
    if(mapVector[locX-1][locY] != '#' && mapVector[locX-1][locY] != 'O'){
        //cout << locX << " to ";
        locX -= 1;
        
    }else Rotate(First);
}

void Map::moveRight(bool First){
    if(locY == mapVector[locX].size() - 1 ) {
        out = true;
        return;
    }
    if(mapVector[locX][locY+1] != '#' && mapVector[locX][locY+1] != 'O'){
        locY += 1;
    }else Rotate(First);
}

void Map::moveDown(bool First){
    if(locX == mapVector.size() - 1) {
        out = true;
        return;
    }
    if(mapVector[locX+1][locY] != '#' && mapVector[locX+1][locY] != 'O'){
        locX += 1;
    }else Rotate(First);
}

void Map::moveLeft(bool First){
    if(locY == 0) {
        out = true;
        return;
    }
    if(mapVector[locX][locY-1] != '#' && mapVector[locX][locY-1] != 'O'){
        locY -= 1;
    }else Rotate(First);
}

void Map::Rotate(bool First){
    switch (Direction)
    {
        case Dir::up:
            Direction = Dir::right;
            break;
        case Dir::right:
            Direction = Dir::down;
            break;
        case Dir::down:
            Direction = Dir::left;
            break;
        case Dir::left:
            Direction = Dir::up;
            break;
    }
    if(!First){
        if(ChechIfLoop()){
            loop = true;
            out = true;
            return;
        }
        RotXsave.push_back(locX);
        RotYsave.push_back(locY);
        RotDirSave.push_back(Direction);
    }    
}

bool Map::ChechIfLoop(){
    for (int i = 0; i < RotXsave.size(); i += 1){
        if(locX == RotXsave[i] && locY == RotYsave[i] && RotDirSave[i] == Direction){
            return true;
        }
    }
    return false;
}


