#include "lib.h"
#include "conio.h"
#include <iostream>

void generateFruit(int &x, int &y, char Matrix[][MAX_HEIGHT])
{
    int fruitx;
    int fruitY;
    do
    {
        fruitx = 1 + (std::rand() % (MAX_LENGHT - 3));
        fruitY = 1 + (std::rand() % (MAX_HEIGHT - 3));
    } while (Matrix[fruitx][fruitY] != nullBox);
    Matrix[fruitx][fruitY] = fruitChar;
}

void Setup(int &x, int &y, char Matrix[][MAX_HEIGHT])
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
    generateFruit(x, y, Matrix);
    Matrix[x][y] = snakeChar;
}

void Input(int &x, int &y, char Matrix[][MAX_HEIGHT])
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
        /* DEBUG ONLY
        case 'q':
            gameOver = true;
            break;
        */
        default:
            break;
        }
    }
}

void elaborate(int &x, int &y, char Matrix[][MAX_HEIGHT], bool &gameover)
{
    static int snakeSize{1};
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
    if (Matrix[x][y] == borders || Matrix[x][y] == snakeChar) // wall or self-eat
        gameover = true;
    if (Matrix[x][y] == fruitChar) // eat a fruit
    {
        Matrix[x][y] = snakeChar;
        generateFruit(x, y, Matrix);
        snakeSize++;
    }
    else // normal movement
    {
        Matrix[x][y] = snakeChar;
        Matrix[snakeX[snakeSize]][snakeY[snakeSize]] = nullBox;
    }
}