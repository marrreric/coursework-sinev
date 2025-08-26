# Tetris

A classic Tetris implementation in C++ with Raylib, featuring custom memory management through a doubly-linked list and persistent score tracking.

## Game Features

*   **Classic Tetris Gameplay:** All standard rules and mechanics.
*   **Custom Memory Management:** Uses a hand-written doubly-linked list for grid cell management.
*   **Persistent High Score:** Best score is saved to a file and displayed on screen.
*   **Clean Visuals:** Modern graphics with Raylib rendering.

## Screenshot

![Gameplay Screenshot](https://github.com/marrreric/coursework-sinev/blob/main/TETRIS.jpg?raw=true)


## Tech Stack & Implementation Details

*   **Language:** C++17/20
*   **Graphics:** Raylib library
*   **IDE:** Visual Studio
*   **Key Data Structure:** Custom doubly-linked list (`double_linked_list`)
*   **Persistence:** File I/O for high score tracking
*   **Architecture:** Object-oriented design with separation of concerns

## How to Play

| Key           | Action                          |
|---------------|---------------------------------|
| <kbd>←</kbd> <kbd>→</kbd> | Move tetromino horizontally     |
| <kbd>↓</kbd>  | Soft drop (accelerate falling)  |
| <kbd>↑</kbd>  | Rotate tetromino                |
| <kbd>Esc</kbd> | Exit to menu                    |

## Building and Running

### Before
*   Visual Studio 2022
*   Raylib library installed
*   C++17 compatible compiler

### Steps
1. Clone the repository:
    ```bash
    git clone https://github.com/marrreric/coursework-sinev.git
    cd Tetris5
    ```
2. Open the Visual Studio solution file (Tetris5.sln)
3. Build the solution (Ctrl + Shift + B)
4. Run the executable (F5)