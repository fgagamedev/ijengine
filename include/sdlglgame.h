#ifndef SDLGL_GAME_H
#define SDLGL_GAME_H

#include "game.h"
#include "sdl2.h"
#include "libgl.h"
#include "sdl3Dvideo.h"
#include "window.h"


#include <memory>

using std::unique_ptr;
using std::shared_ptr;

namespace ijengine {

    class SDLGLGame : public Game {
    public:
        SDLGLGame();

    private:
        unique_ptr<LibSDL2> m_lib_sdl;
        unique_ptr<LibGL> m_lib_gl;
        unique_ptr<SDL3DVideo> m_video;
        shared_ptr<Window> m_window;
    };

}

#endif
