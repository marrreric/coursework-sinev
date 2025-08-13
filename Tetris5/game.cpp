#include "game.h"
#include "blocks.h"
#include <fstream>
#include <iostream>
#include <string>

Game::Game() : grid(10, 20), isGameOver(false), score(0), bestScore(0) {
    LoadScore();
    currentBlock = new Block(0, grid.GetGridWidth() / 2, GetRandomValue(0, NUM_BLOCK_TYPES - 1));
}

void Game::RestartGame() {
    delete currentBlock;
    grid.Clear();
    currentBlock = new Block(0, grid.GetGridWidth() / 2, GetRandomValue(0, NUM_BLOCK_TYPES - 1));
    isGameOver = false;
    score = 0;
}

bool Game::CheckGameOver() {
    Position* blockCells = currentBlock->GetCellPositions();
    int numCells = currentBlock->GetNumCells();

    for (int i = 0; i < numCells; ++i) {
        if (blockCells[i].row < 1 && !grid.IsCellEmpty(blockCells[i].row, blockCells[i].column)) {
            return true;
        }
    }
    return false;
}

void Game::HandleInput() {
    if (isGameOver) {
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
            RestartGame();
        }
        return;
    }

    if (IsKeyPressed(KEY_LEFT)) {
        if (!CheckCollision(-1, 0)) {
            currentBlock->MoveLeft();
        }
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        if (!CheckCollision(1, 0)) {
            currentBlock->MoveRight();
        }
    }
    if (IsKeyPressed(KEY_DOWN)) {
        if (!CheckCollision(0, 1)) {
            currentBlock->MoveDown();
        }
    }
    if (IsKeyPressed(KEY_UP)) {
        currentBlock->Rotate();
        if (CheckCollision(0, 0)) {
            currentBlock->RotateBack();
        }
    }
}

void Game::MoveBlockDown() {
    if (isGameOver) return;

    if (!CheckCollision(0, 1)) {
        currentBlock->MoveDown();
    }
    else {
        MergeBlockToGrid();
        AddScore(4); 

        int clearedRows = grid.ClearFullRows();
        if (clearedRows > 0) {
            AddScore(clearedRows * 100); 
        }

        if (CheckGameOver()) {
            isGameOver = true;
            SaveScore();  
        }
        else {
            delete currentBlock;
            currentBlock = new Block(0, grid.GetGridWidth() / 2, GetRandomValue(0, NUM_BLOCK_TYPES - 1));
        }
    }
}

void Game::MergeBlockToGrid() {
    Position* blockCells = currentBlock->GetCellPositions();
    int numCells = currentBlock->GetNumCells();
    Color color = currentBlock->GetColor();

    grid.PlaceBlock(blockCells, numCells, color);
}

bool Game::CheckCollision(int dx, int dy) {
    Position* blockCells = currentBlock->GetCellPositions();
    int numCells = currentBlock->GetNumCells();

    for (int i = 0; i < numCells; ++i) {
        int newRow = blockCells[i].row + dy;
        int newCol = blockCells[i].column + dx;
        if (grid.IsCellOutside(newRow, newCol) || !grid.IsCellEmpty(newRow, newCol)) {
            return true;
        }
    }
    return false;
}

void Game::Draw() {
    if (isGameOver) {
        DrawText("Game Over", 20, 200, 50, RED);
        DrawText("Press SPACE or ENTER", 20, 280, 20, WHITE);
        DrawText(TextFormat("Best Score: %d", GetBestScore()), 10, 40, 20, WHITE); 
        return;
    }

    grid.Draw(cellSize, 0, 0);
    currentBlock->Draw(cellSize);
    DrawText(TextFormat("Score: %d", GetScore()), 10, 10, 20, WHITE); 
    DrawText(TextFormat("Best Score: %d", GetBestScore()), 10, 40, 20, WHITE); 
}

void Game::AddScore(int value) {
    score += value;
    if (score > bestScore) {
        bestScore = score;
    }
}

int Game::GetScore() const {
    return score;
}

int Game::GetBestScore() const {
    return bestScore;
}

void Game::SaveScore() {
    std::ofstream outFile("bestscore.txt");
    if (outFile.is_open()) {
        outFile << bestScore;
        outFile.close();
    }
    else {
        std::cerr << "Unable to save score." << std::endl;
    }
}

void Game::LoadScore() {
    std::ifstream inFile("bestscore.txt");
    if (inFile.is_open()) {
        std::string line;
        if (std::getline(inFile, line)) {
            bestScore = std::stoi(line);
        }
        inFile.close();
    }
    else {
        std::cerr << "Unable to load score." << std::endl;
    }
}