#include "block.h"
#include "blocks.h"
#include "colors.h"
#include <vector>

// Конструктор инициализирует блок заданного типа в начальной позиции
Block::Block(int startX, int startY, int blockType)
    : origin(startX, startY), rotationState(0), type(blockType) {
    auto colors = GetCellColors();
    color = colors[blockType + 1];
    SetShape();
}

Block::~Block() {}

void Block::SetShape() {
    GetBlockShape(type, rotationState, cells, numCells);
    for (int i = 0; i < numCells; ++i) {
        cells[i].row += origin.row;
        cells[i].column += origin.column;
    }
}

void Block::MoveLeft() {
    for (int i = 0; i < numCells; ++i) {
        cells[i].column -= 1;
    }
    origin.column -= 1;
}

void Block::MoveRight() {
    for (int i = 0; i < numCells; ++i) {
        cells[i].column += 1;
    }
    origin.column += 1;
}

void Block::MoveDown() {
    for (int i = 0; i < numCells; ++i) {
        cells[i].row += 1;
    }
    origin.row += 1;
}

void Block::Rotate() {
    if (type == O_BLOCK) return; // O-Block не вращается

    rotationState = (rotationState + 1) % 4;
    SetShape();
}

void Block::RotateBack() {
    if (type == O_BLOCK) return; // O-Block не вращается

    rotationState = (rotationState - 1 + 4) % 4;
    SetShape();
}

Position* Block::GetCellPositions() {
    return cells;
}

int Block::GetNumCells() const {
    return numCells;
}

Color Block::GetColor() const {
    return color;
}

void Block::Draw(int cellSize) const {
    for (int i = 0; i < numCells; ++i) {
        int x = cells[i].column * cellSize;
        int y = cells[i].row * cellSize;
        DrawRectangle(x, y, cellSize - 1, cellSize - 1, color); 
    }
}