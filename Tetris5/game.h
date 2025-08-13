#pragma once

#include "block.h"
#include "cellnode.h"
#include "grid.h"
#include <raylib.h>
#include <fstream>
#include <string>

class Game {
public:
    Game();
    void HandleInput();
    void MoveBlockDown();
    void Draw();
    void RestartGame();
    bool CheckGameOver();
    int GetScore() const;
    int GetBestScore() const;  

private:
    const int cellSize = 30;
    Grid grid;
    Block* currentBlock;
    bool isGameOver;
    int score;
    int bestScore; 

    void MergeBlockToGrid();
    void AddScore(int value);
    bool CheckCollision(int dx, int dy);

    void SaveScore();  
    void LoadScore();  
};