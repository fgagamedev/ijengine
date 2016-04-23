#include "sdl2game.h"
#include "engine.h"
#include "SDL2/SDL.h"
#include <iostream>

using namespace ijengine;

int main()
{
    video::make_video();
    
    SDL2Game game("Teste", 800, 600);

    return game.run("green");
}
