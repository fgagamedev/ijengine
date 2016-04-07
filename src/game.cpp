#include "game.h"

#include <iostream>
using namespace std;

namespace ijengine {

    Game::Game()
    {
        cout << "Initializing...\n";
    }

    Game::~Game()
    {
        cout << "Shutting down...\n";
    }

    int
    Game::run()
    {
        cout << "Hello World\n";

        return 0;
    }

}
