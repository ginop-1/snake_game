#include <iostream>
#include "lib.h"
#include <chrono>
#include <thread>

int main()
{
    std::srand(time(NULL));
    Setup();
    while (!gameOver)
    {
        printGraphics();
        Input();
        elaborate();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    return 0;
}
