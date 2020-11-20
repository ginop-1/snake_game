#include <iostream>
#include "lib.h"

void Clear()
{
#if defined _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printGraphics(char Matrix[][MAX_HEIGHT])
{
    Clear();
    for (auto i = 0; i < MAX_LENGHT; i++)
    {
        for (auto j = 0; j < MAX_HEIGHT; j++)
            std::cout << Matrix[i][j];
        std::cout << std::endl;
    }
}