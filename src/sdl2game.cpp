#include "sdl2game.h"
#include "sdl2texture.h"
#include "sdl2animation.h"
#include <SDL2/SDL_image.h>
#include "sdl2canvas.h"

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

        /* Test of textures and animations starts below */
        SDL2Texture *textu = SDL2Texture::load_texture_from_path("test/animation-test.png", m_window->canvas());

        SDL2Animation anim(textu, SDL2Animation::RenderStyle::STATE_PER_ROW, 4, 2);
        SDL2Animation anim2(textu, SDL2Animation::RenderStyle::STATE_PER_ROW, 4, 2);

        anim2.actual_state = 1;

        SDL2Texture *tex = SDL2Texture::load_texture_from_path("test/img-test.png", m_window->canvas());

        SDL2Canvas *c = dynamic_cast<SDL2Canvas *>(m_window->canvas());
        SDL_Rect final_dest {200, 200, anim.texture()->w(), anim.texture()->h()};
        SDL_Rect other_dest {400, 400, anim.texture()->w(), anim.texture()->h()};

        for (int i=0; i < 30; ++i)
        {
            anim.update();
            anim2.update();

            c->clear_renderer();
            c->draw_from_rectangle(anim.texture(), *anim.source(), final_dest);
            c->draw_from_rectangle(anim2.texture(), *anim2.source(), other_dest);

            m_window->canvas()->draw(tex, 0, 0);
            m_window->canvas()->update();

            SDL_Delay(100);
        }
        /* Test of textures and animations and here */
    }

}
