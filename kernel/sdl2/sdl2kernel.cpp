#include "sdl2kernel.h"
#include "sdl2window.h"
#include "sdl2time.h"
#include "exception.h"
#include "event.h"
#include "system_event.h"
#include "keyboard_event.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace ijengine;

SDL2Kernel::SDL2Kernel()
{
    int rc = SDL_Init(SDL_INIT_VIDEO);
    if (rc)
        throw Exception("Error on SDL2Kernel()");
    m_timer = new SDL2Time();
}

SDL2Kernel::~SDL2Kernel()
{
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Quit();
}

Window *
SDL2Kernel::create_window(const string& title, int w, int h)
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer))
        return nullptr;

    SDL_SetWindowTitle(window, title.c_str());

    return new SDL2Window(window, renderer);
}

list<event_t>
SDL2Kernel::pending_events(unsigned now)
{
    SDL_Event event;
    list<event_t> events;

    SDL_PumpEvents();

    while (SDL_PeepEvents(&event, 1, SDL_PEEKEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT) > 0)
    {
        unsigned timestamp = event.quit.timestamp;

        if (timestamp > now)
            break;

        SDL_PollEvent(&event);
        
        switch (event.type) {
        case SDL_QUIT:
            {
                auto p = SystemEvent(timestamp, SystemEvent::Action::QUIT);
                events.push_back(event_t(timestamp, p.serialize()));
            }

            break;

        case SDL_KEYDOWN:
        case SDL_KEYUP:
            {
                auto p = KeyboardEvent(timestamp,
                    KeyboardEvent::State::PRESSED,
                    KeyboardEvent::Key::ESCAPE,
                    KeyboardEvent::Modifier::NONE);

                events.push_back(event_t(timestamp, p.serialize()));
            }
            break;

        default:
            break;
        }

        SDL_PumpEvents();
    }

    return events;
}

unsigned
SDL2Kernel::time_elapsed() {
    return m_timer->time_elapsed();
}

void
SDL2Kernel::pause_timer() {
    m_timer->pause_timer();
}

void
SDL2Kernel::resume_timer() {
    m_timer->resume_timer();
}
