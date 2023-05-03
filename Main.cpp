#include "Graphics.h"
#include "Random.h"
#include <iostream>
#include <SDL.h>
#include <glm/glm.hpp>

using namespace std;

int main(int argc, char* argv[])
{
    Graphics graphics;

    graphics.CreateWindow("Physics", 800, 600);
    graphics.Clear();
    while (1)
    {
        graphics.DrawPoint({ randomf(800), randomf(600) }, { randomf(), randomf(), randomf(), 1});
    }
    graphics.Present();
    

    SDL_Delay(5000);

    return 0;
}