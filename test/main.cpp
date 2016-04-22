#include "sdl2game.h"
#include "SDL2/SDL.h"
#include <iostream>

using namespace ijengine;

int main()
{
    SDL2Game game("Teste", 800, 600);

    return game.run();
}
