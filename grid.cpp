#include "grid.h"
#include <iostream>

gameGrid::gameGrid() {
    numRows = 20;
    numCols = 10;
    squareSize = 50;
    createGrid();
}

void gameGrid::createGrid() {
    for(int rows = 0; rows < numRows; rows++) {
        for(int cols = 0; cols <numCols; cols++) {
            grid[rows][cols] = 0;
        }
    }
}

void gameGrid::printEmptyGrid() {
      for(int rows = 0; rows < numRows; rows++) {
        for(int cols = 0; cols <numCols; cols++) {
            int cellNum = grid[rows][cols];
            DrawRectangle(cols * squareSize+1,rows * squareSize+1 ,squareSize-1,squareSize-1, colors[cellNum]);
        }
      }
}
bool gameGrid::isInsideGrid(int row, int col) {
    return (row < numRows && col < numCols && row >= 0 && col >= 0);
}

bool gameGrid::isBlockEmpty(int row, int col) {
    return(grid[row][col] == 0);
}

int gameGrid::clearCompleteRows() {
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--) {
        bool rowFull = true;
        for (int column = 0; column < numCols; column++) {
            if (grid[row][column] == 0) {
                rowFull = false;
                break;
            }
        }
        if (rowFull) {
            // Clear the row
            for (int column = 0; column < numCols; column++) {
                grid[row][column] = 0;
            }
            completed++;
            // Move rows down
            for (int moveRow = row - 1; moveRow >= 0; moveRow--) {
                for (int column = 0; column < numCols; column++) {
                    grid[moveRow + 1][column] = grid[moveRow][column];
                    grid[moveRow][column] = 0;
                }
            }
            // Check the same row again
            row++;
        }
    }
    return completed;
}