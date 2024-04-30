#include "tetris.h"
#include <iostream>
#include <raylib.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>   
#include <cstring>
#include "grid.h" 
#include "tetrominoes.h"

void DrawTitleScreen() {
    //Color randomColor = colors[rand() % (sizeof(colors) / sizeof(colors[0]))];

    BeginDrawing();

    ClearBackground(BLACK);
    DrawRectangle(screenWidth / 2 - 47, 80, 80, 120, WHITE);
    DrawRectangle(screenWidth / 2 - 114, 45, 220, 80, WHITE);

    DrawRectangle(screenWidth / 2 - 47+1, 80+1, 80-2, 120-2, graphic);
    DrawRectangle(screenWidth / 2 - 114+1, 45+1, 220-2, 80-2, graphic);
       
    DrawText("TETRIS 327", 195, 60, 50, MAGENTA);
    EndDrawing();
}
void DrawScore() {
    DrawText("Score",505,150,30,WHITE);
    DrawText(TextFormat("%d", score), 545, 110,40,WHITE);
}
void DrawGameOverScreen() {
    BeginDrawing();
    
    ClearBackground(BLACK); // Clear the background to white

    // Draw game over text
    DrawText("Game Over", GetScreenWidth() / 2 - MeasureText("Game Over", 40) / 2, GetScreenHeight() / 2 - 40, 40, RED);

    // Draw final score
    DrawText(TextFormat("Final Score: %d", score), GetScreenWidth() / 2 - MeasureText("Score: %d", 20) / 2, GetScreenHeight() / 2, 20, BLACK);

    // Draw instructions to restart the game
    DrawText("Press SPACE/ESC to exit", GetScreenWidth() / 2 - MeasureText("Press SPACE/ESC to exit", 20) / 2, GetScreenHeight() / 2 + 40, 20, GRAY);

    EndDrawing();
}
tetrominoe getRandomTetrominoe() {
    return tetrominoes[rand() % 7];
}

void handleInputs() {
    if(!isOver) {
    int input = GetKeyPressed();
    switch(input) {
        case KEY_A:
            currentTetrominoe.move(0,-1);
            if(notInGrid()) {
                currentTetrominoe.move(0,1);
            }
        break;

        case KEY_D:
            currentTetrominoe.move(0, 1);
            if(notInGrid()) {
                currentTetrominoe.move(0,-1);
            }
        break;
            
        case KEY_S:
            currentTetrominoe.move(1,0);
            if(notInGrid()) {
                currentTetrominoe.move(-1,0);
            }
        break;

        case KEY_W:
            currentTetrominoe.rotateTetronimoe();
            //if it would rotate part of it out of bounds return to original state
            if(notInGrid()) {
                currentTetrominoe.rotateTetronimoe();
                currentTetrominoe.rotateTetronimoe();
                currentTetrominoe.rotateTetronimoe();
            }
        break;
    }
    }
}
bool notInGrid() {
    std::vector<position> tiles = currentTetrominoe.GetCellPositions();
    for(position block: tiles) {
        if(!grid.isInsideGrid(block.row,block.col) || !grid.isBlockEmpty(block.row, block.col)) {
            return true;
        }
    }
    return false;
}

void cementTetronomoe() {
    if(!isOver) {
    std::vector<position> tiles = currentTetrominoe.GetCellPositions();
    for(position block : tiles) {
        grid.grid[block.row][block.col] = currentTetrominoe.id;
    }
    currentTetrominoe = getRandomTetrominoe();
    score += grid.clearCompleteRows();
    if(notInGrid()) {
        isOver = true;
    }
    }
}
void gameloop() {
    while (WindowShouldClose() == false){
        if(isOver) {
            break;
            }
        float deltaTime = GetFrameTime();
        elapsedTime += deltaTime;
        handleInputs();
        //gameTimer
        if(elapsedTime >= moveInterval) {
            
            currentTetrominoe.move(1,0);
            if(notInGrid()) {  
                //if it was attempted to break out instead cement blocks position
                currentTetrominoe.move(-1,0);
                cementTetronomoe();
            }


            elapsedTime = 0.0f;
        }

        BeginDrawing();
        ClearBackground(background); 

        grid.printEmptyGrid();

        currentTetrominoe.createTetrominoe();

        DrawScore();
       
        EndDrawing();
    }
}
int main () {
    std::cout << "Creating Tetris Window" << std::endl;

    srand(time(NULL));

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(30);

    currentTetrominoe = tetrominoes[rand() % numTetrominoes];
    

    while(WindowShouldClose() == false) {
        DrawTitleScreen();

        if(GetKeyPressed() == KEY_SPACE) {
            break;
        }
    }
    gameloop();

    while(WindowShouldClose() == false) {
        DrawGameOverScreen();

        if(GetKeyPressed() == KEY_SPACE) {
            break;
        }
    }
    CloseWindow();
    return 0;
}