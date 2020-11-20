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

inline Direction dir(Direction::UP);

// int snakeX[200], snakeY[200]; SHIT
const char fruitChar = 'A';
const char snakeChar = 'O';
const char borders = '#';
const char nullBox = ' ';

// FUNCTION

// Frontend
void Clear();           // Clear screen
void printGraphics(char Matrix[][MAX_HEIGHT]);   // Print Matrix

// Backend
void Setup(int &x, int &y, char Matrix[][MAX_HEIGHT]);                          // Initialize Matrix
void generateFruit(int &x, int &y, char Matrix[][MAX_HEIGHT]);                  // Generate random position for fruit
void Input(int &x, int &y, char Matrix[][MAX_HEIGHT]);                          // Read input from user
void elaborate(int &x, int &y, char Matrix[][MAX_HEIGHT], bool &gameover);       // Game logic
