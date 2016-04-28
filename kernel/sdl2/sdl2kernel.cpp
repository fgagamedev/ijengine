#include "sdl2kernel.h"
#include "sdl2window.h"
#include "exception.h"
#include "keyboard_input.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace ijengine;


SDL2Kernel::SDL2Kernel()
{
    int rc = SDL_Init(SDL_INIT_VIDEO);

    if (rc)
        throw Exception("Error on SDL2Kernel()");
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

list<Input>
SDL2Kernel::pending_inputs(unsigned now)
{
    SDL_Event event;
    list<Input> inputs;

    SDL_PumpEvents();

    while (SDL_PeepEvents(&event, 1, SDL_PEEKEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT) > 0)
    {
        unsigned timestamp = event.quit.timestamp;

        if (timestamp > now)
            break;

        SDL_PollEvent(&event);
        
        Input input(timestamp);

        switch (event.type) {
        case SDL_QUIT:
            input.system = SystemInput(SystemInput::Action::QUIT);
            break;

        case SDL_KEYDOWN:
        case SDL_KEYUP:
        input.keyboard = KeyboardInput(KeyboardInput::State::PRESSED,
            KeyboardInput::Key::ESCAPE, KeyboardInput::Modifier::NONE);
            break;

        default:
            input.type = UNKNOWN_INPUT;
            break;
        }

        inputs.push_back(input);
        SDL_PumpEvents();
    }

    return inputs;
}

