#include "sdlglgame.h"
#include "GL/gl.h"

#include <memory>
using std::make_shared;

namespace ijengine {

    SDLGLGame::SDLGLGame()
        : m_lib_sdl(new LibSDL2())
    {
        if (m_lib_sdl)
            m_lib_sdl->init();

        m_video = unique_ptr<SDL3DVideo>(new SDL3DVideo());

        if (not m_video)
            throw "Error on SDLGLGame::SDLGLGame()";

        m_window = shared_ptr<Window>(m_video->create_window(800, 600));

        if (not m_window)
            throw "Error on SDLGLGame::SDLGLGame()";
       
        m_lib_gl = unique_ptr<LibGL>(new LibGL());
        if (m_lib_gl)
            m_lib_gl->init();
        m_lib_gl->config("GL_VERSION_3_3", "3.3");
         SDL_Delay(3000);
    }

}
