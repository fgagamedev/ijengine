#include "sdl2kernel.h"
#include "sdl2window.h"
#include "exception.h"
#include "keyboard_input.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace ijengine;


SDL2Kernel::SDL2Kernel()
{
    printf("Initializing kernel...\n");
    int rc = SDL_Init(SDL_INIT_VIDEO);

    if (rc)
        throw Exception("Error on SDL2Kernel()");
}

SDL2Kernel::~SDL2Kernel()
{
    printf("Destroying kernel...\n");
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

vector<Input *>
SDL2Kernel::pending_inputs(unsigned now)
{
    SDL_Event event;
    vector<Input *> inputs;

    SDL_PumpEvents();

    while (SDL_PeepEvents(&event, 1, SDL_PEEKEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT) > 0)
    {
        unsigned timestamp = event.quit.timestamp;
printf("timestamp lido = %u\n", timestamp);

        if (timestamp > now)
            break;

        SDL_PollEvent(&event);
        
        inputs.push_back(new KeyboardInput(KeyboardInput::State::PRESSED, KeyboardInput::Key::ESCAPE,
            KeyboardInput::Modifier::NONE, timestamp));

        SDL_PumpEvents();
    }

    return inputs;
}

