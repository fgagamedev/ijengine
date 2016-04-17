#include "sdl2game.h"
#include "sdl2texture.h"
#include <SDL2/SDL_image.h>

#include <memory>
using std::make_shared;

namespace ijengine {

    SDL2Game::SDL2Game()
        : m_lib(new LibSDL2())
    {
        if (m_lib)
            m_lib->init();

        m_video = unique_ptr<SDL2DVideo>(new SDL2DVideo());

        if (not m_video)
            throw "Error on SDL2Game::SDL2Game()";

        m_window = shared_ptr<Window>(m_video->create_window(800, 600));

        if (not m_window)
            throw "Error on SDL2Game::SDL2Game()";


        SDL2Texture *tex = SDL2Texture::load_texture_from_path("test/img-test.png", m_window->canvas());

        m_window->canvas()->draw(tex, 0, 0);
        m_window->canvas()->update();

        SDL_Delay(3000);
    }

}
