#include <iostream>
#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

// Функция для контроля времени обновления
bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime; 
        return true; 
    }
    return false; 
}

int main() {
    
    InitWindow(300, 620, "Tetris");
    SetTargetFPS(60);
    Color darkBlue = { 44, 44, 127, 255 };

    
    Game game;

    
    while (!WindowShouldClose()) {
        
        game.HandleInput();
        
        if (EventTriggered(0.2)) { 
            game.MoveBlockDown();
        }

        // Отрисовка
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw(); 
        EndDrawing();
    }

    CloseWindow();
    return 0;
}