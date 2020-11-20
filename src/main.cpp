#include <iostream>
#include "lib.h"
#include <chrono>
#include <thread>

int main()
{
    // Setup part
    std::srand(time(NULL));
    char Matrix[MAX_LENGHT][MAX_HEIGHT] {};
    int x = MAX_LENGHT/2;
    int y = MAX_HEIGHT/2;
    Setup(x, y, Matrix);
    bool gameOver {false};
    while (!gameOver)
    {
        printGraphics(Matrix);
        Input(x, y, Matrix);
        elaborate(x, y, Matrix, gameOver);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    return 0;
}
