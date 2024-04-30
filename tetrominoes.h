#ifndef TETROMINOES_H
#define TETROMINOES_H

#include <vector>
#include <map>
#include "position.h"
#include <raylib.h>

//base structure for tetrominoes to inherit from
class tetrominoe {
    public:
    tetrominoe();
    void createTetrominoe();
    void move(int row, int col);
    std::vector<position> GetCellPositions();
    int id;
    std::map<int, std::vector<position>> cells;
    void rotateTetronimoe();
    void cementTetronimoe();
    private:
    int cellSize;
    int rotationState;
    //added an extra color to offset it for the id's
    Color colors[8] = {MAROON,RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, SKYBLUE};
    int Trow;
    int Tcol;
};

class Ltetrominoe : public tetrominoe {
    public:
        Ltetrominoe();
};

class Jtetrominoe : public tetrominoe {
    public:
        Jtetrominoe();
};

class Itetrominoe : public tetrominoe {
    public:
        Itetrominoe();
};

class Otetrominoe : public tetrominoe {
    public:
        Otetrominoe();
};

class Stetrominoe : public tetrominoe {
    public:
        Stetrominoe();
};

class Ttetrominoe : public tetrominoe {
    public:
        Ttetrominoe();
};

class Ztetrominoe : public tetrominoe {
    public:
        Ztetrominoe();
};

#endif