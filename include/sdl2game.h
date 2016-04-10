#ifndef SDL2_GAME_H
#define SDL2_GAME_H

#include "game.h"
#include "sdl2.h"
#include "sdl2Dvideo.h"
#include "window.h"

#include <memory>

using std::unique_ptr;
using std::shared_ptr;

namespace ijengine {

    class SDL2Game : public Game {
    public:
        SDL2Game();

    private:
        unique_ptr<LibSDL2> m_lib;
        unique_ptr<SDL2DVideo> m_video;
        shared_ptr<Window> m_window;
    };

}

#endif
