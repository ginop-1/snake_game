#pragma once


const int MAX_LENGHT {20};
const int MAX_HEIGHT {20};

enum class Direction
{
    RIGHT,
    LEFT,
    UP,
    DOWN
};

inline bool gameOver {false};

inline Direction dir(Direction::UP);

inline char Matrix[MAX_LENGHT][MAX_HEIGHT];
inline int x = MAX_LENGHT/2;
inline int y = MAX_HEIGHT/2;

// int snakeX[200], snakeY[200]; SHIT
const char fruitChar = 'A';
const char snakeChar = 'O';
const char borders = '#';
const char nullBox = ' ';

// FUNCTION

// Frontend
void Clear();           // Clear screen
void printGraphics();   // Print Matrix

// Backend
void Setup();           // Initialize Matrix
void generateFruit();   // Generate random position for fruit
void Input();           // Read input from user
void elaborate();       // Game logic
