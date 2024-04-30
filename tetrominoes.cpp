#include "tetrominoes.h"
#include "position.h"

tetrominoe::tetrominoe() {
    cellSize = 50;
    rotationState = 0;
    Trow = 0;
    Tcol = 0;
}

void tetrominoe::createTetrominoe() {
    std::vector<position> tiles = GetCellPositions();
    for(position item: tiles) {
        DrawRectangle(item.col * cellSize+1, item.row * cellSize+1, cellSize-1,cellSize-1, colors[id]);
    }
}

void tetrominoe::move(int row, int col) {
    Trow += row;
    Tcol += col;
}

std::vector<position> tetrominoe::GetCellPositions() {
    std::vector<position> tiles = cells[rotationState];
    std::vector<position> movedTiles;

    for(position item: tiles) {
        position newpos = position(item.row + Trow, item.col + Tcol);
        movedTiles.push_back(newpos);
    }

    return movedTiles;
}
void tetrominoe::rotateTetronimoe() {
    rotationState++;
    if(rotationState == 4) {
        rotationState = 0;
    }
 }

Ltetrominoe::Ltetrominoe() {
    id = 1;
    // Initialize cells array with positions for each rotation state
    cells[0] = {position(0, 2), position(1, 0), position(1, 1), position(1, 2)};
    cells[1] = {position(0, 1), position(1, 1), position(2, 1), position(2, 2)};
    cells[2] = {position(1, 0), position(1, 1), position(1, 2), position(2, 0)};
    cells[3] = {position(0, 0), position(0, 1), position(1, 1), position(2, 1)};
}

Jtetrominoe::Jtetrominoe() {
        id = 2;
        cells[0] = {position(0, 0), position(1, 0), position(1, 1), position(1, 2)};
        cells[1] = {position(0, 1), position(0, 2), position(1, 1), position(2, 1)};
        cells[2] = {position(1, 0), position(1, 1), position(1, 2), position(2, 2)};
        cells[3] = {position(0, 1), position(1, 1), position(2, 0), position(2, 1)};
    }

Itetrominoe::Itetrominoe() {
        id = 3;
        cells[0] = {position(1, 0), position(1, 1), position(1, 2), position(1, 3)};
        cells[1] = {position(0, 2), position(1, 2), position(2, 2), position(3, 2)};
        cells[2] = {position(2, 0), position(2, 1), position(2, 2), position(2, 3)};
        cells[3] = {position(0, 1), position(1, 1), position(2, 1), position(3, 1)};
    }

Otetrominoe::Otetrominoe() {
        id = 4;
        cells[0] = {position(0, 0), position(0, 1), position(1, 0), position(1, 1)};
    }

Stetrominoe::Stetrominoe() {
        id = 5;
        cells[0] = {position(0, 1), position(0, 2), position(1, 0), position(1, 1)};
        cells[1] = {position(0, 1), position(1, 1), position(1, 2), position(2, 2)};
        cells[2] = {position(1, 1), position(1, 2), position(2, 0), position(2, 1)};
        cells[3] = {position(0, 0), position(1, 0), position(1, 1), position(2, 1)};
    }

Ttetrominoe::Ttetrominoe() {
        id = 6;
        cells[0] = {position(0, 1), position(1, 0), position(1, 1), position(1, 2)};
        cells[1] = {position(0, 1), position(1, 1), position(1, 2), position(2, 1)};
        cells[2] = {position(1, 0), position(1, 1), position(1, 2), position(2, 1)};
        cells[3] = {position(0, 1), position(1, 0), position(1, 1), position(2, 1)};
    }


Ztetrominoe::Ztetrominoe() {
        id = 7;
        cells[0] = {position(0, 0), position(0, 1), position(1, 1), position(1, 2)};
        cells[1] = {position(0, 2), position(1, 1), position(1, 2), position(2, 1)};
        cells[2] = {position(1, 0), position(1, 1), position(2, 1), position(2, 2)};
        cells[3] = {position(0, 1), position(1, 0), position(1, 1), position(2, 0)};
    }