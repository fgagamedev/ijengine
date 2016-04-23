#include "sdl2game.h"
#include "engine.h"
#include "exception.h"
#include "SDL2/SDL.h"
#include <iostream>

using namespace ijengine;
using namespace std;

int main()
{
    try
    {
        Engine engine;
    } catch (Exception& ex)
    {
        cout << ex.what() << endl;
    }

//    SDL2Game game("Teste", 800, 600);

 ////   return game.run("green");
    return 0;
}
