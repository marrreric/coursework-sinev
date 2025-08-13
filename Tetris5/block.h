#pragma once

#include "position.h"
#include "colors.h"
#include <raylib.h>

const int MAX_BLOCK_CELLS = 4;

class Block {
public:
    Block(int startX, int startY, int blockType); 
    ~Block();

    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void Rotate();
    void RotateBack();
    void Draw(int cellSize) const;
    Position* GetCellPositions();
    int GetNumCells() const;
    Color GetColor() const;

private:
    Position cells[MAX_BLOCK_CELLS];
    int numCells;
    Position origin;
    int rotationState;
    Color color;
    int type;

    void SetShape();
};
