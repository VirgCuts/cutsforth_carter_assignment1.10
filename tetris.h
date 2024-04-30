#ifndef TETRIS_H
#define TETRIS_H

#include <raylib.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include "grid.h"
#include "tetrominoes.h"

const int screenWidth = 600;
const int screenHeight = 1000;
const float moveInterval = 0.5f;
float elapsedTime = 0.0f;

const Color background = BLACK;
const Color graphic = {46, 46, 132, 255};
Color colors[8] = {MAROON,RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, SKYBLUE};
const tetrominoe tetrominoes[] = {Ltetrominoe(), Ztetrominoe(), Jtetrominoe(), Itetrominoe(), Otetrominoe(), Stetrominoe(), Ttetrominoe()};
const int numTetrominoes = 7;
gameGrid grid = gameGrid();
tetrominoe currentTetrominoe;

tetrominoe getRandomTetrominoe();
void handleInputs();
bool notInGrid();
bool spaceToggle = false;
bool isOver = false;
int score = 0;

#endif // TETRIS_H