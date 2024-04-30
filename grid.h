#ifndef GRID_H
#define GRID_H

#include <raylib.h>

class gameGrid {
    public:
    gameGrid();
    void createGrid();
    void printGrid();
    int grid[20][10];
    void printEmptyGrid();
    bool isInsideGrid(int row, int col);
    bool isBlockEmpty(int row, int col);
    int clearCompleteRows();
    private:
    Color* getColors(void);
    
    int numRows;
    int numCols;
    int squareSize;

    Color colors[8] = {GRAY, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, SKYBLUE};
};
#endif
