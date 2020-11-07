#include "lib.h"
#include "conio.h"
#include <iostream>

void generateFruit()
{
    int fruitx = 1 + (std::rand() % (MAX_LENGHT - 3)); 
    int fruitY = 1 + (std::rand() % (MAX_HEIGHT - 3));
    Matrix[fruitx][fruitY] = fruitChar;
}

void Setup()
{
    for (auto i = 0; i < MAX_LENGHT; i++)
    {
        for (auto j = 0; j < MAX_HEIGHT; j++)
        {
            if (i == 0 || j == 0 || j == MAX_HEIGHT - 1 || i == MAX_LENGHT - 1)
                Matrix[i][j] = borders;
            else
                Matrix[i][j] = nullBox;
        }
    }
    generateFruit();
    Matrix[x][y] = snakeChar;
}

void Input()
{
    char input;
    if (kbhit())
    {
        switch (input = getch())
        {
        case 'a':
            dir = Direction::LEFT;
            break;
        case 'w':
            dir = Direction::UP;
            break;
        case 's':
            dir = Direction::DOWN;
            break;
        case 'd':
            dir = Direction::RIGHT;
            break;
        case 'q':
            gameOver = true;
            break;
        default:
            break;
        }
    }
}

void elaborate()
{
    static int snakeSize {1};
    static int snakeX[200];
    static int snakeY[200];
    snakeX[0] = x;
    snakeY[0] = y;
    // we use an array for every position of snake's tail
    for (int i = snakeSize; i > 0; i--)
    {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }
    switch (dir)
    {
    case Direction::UP:
        x--;
        break;
    case Direction::DOWN:
        x++;
        break;
    case Direction::RIGHT:
        y++;
        break;
    case Direction::LEFT:
        y--;
        break;
    default:
        break;
    }
    if (Matrix[x][y] == borders || Matrix[x][y] == snakeChar)   // wall or self-eat
        gameOver = true;
    if (Matrix[x][y] == fruitChar)                              // eat a fruit
    {
        Matrix[x][y] = snakeChar;
        generateFruit();
        snakeSize++;
    }
    else                                                        // normal movement
    {
        Matrix[x][y] = snakeChar;
        Matrix[snakeX[snakeSize]][snakeY[snakeSize]] = nullBox;
    }
}