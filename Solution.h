#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum Dir{
    up,
    right,
    down,
    left,
    
};

class Map{
    public:
    Map(string mapName);
    
    Dir Direction = Dir::up;
    int locX;
    int locY;
    vector<string> mapVector;
    vector<string> mapVectorOri;
    vector<int> LocXsave;
    vector<int> LocYsave;
    vector<Dir> LocRotsave;
    vector<int> RotXsave;
    vector<int> RotYsave;
    vector<Dir> RotDirSave;

    bool out = false;
    bool loop = false;
    int spaces = 1;
    int spacesReRow = 0;

    void moveGuard(bool First);
    void moveUp(bool First);
    void moveRight(bool First);
    void moveDown(bool First);
    void moveLeft(bool First);
    void Rotate(bool First);
    bool ChechIfLoop();
};



