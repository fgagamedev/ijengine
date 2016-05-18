#include "sdl2kernel.h"
#include "sdl2window.h"
#include "sdl2time.h"
#include "sdl2texture.h"
#include "sdl2canvas.h"
#include "exception.h"
#include "event.h"
#include "system_event.h"
#include "keyboard_event.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

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

void
SDL2Kernel::play_audio_from_path(const string& path)
{
    if(path.empty())
        printf("Empty audio path\n");

    int init_audio = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    if(init_audio < 0)
        printf("Audio not initialized\n");

    Mix_Music *audio;

    printf("audio path: [%s]\n", path.c_str());
    audio = Mix_LoadMUS(path.c_str());

    if(not audio){
        printf("Failed to load audio\n");
        printf("error: %s\n", Mix_GetError());
    }

    if(Mix_PlayingMusic() == 0)
    {
        printf("Sem musica no momento\n");
        Mix_PlayMusic(audio, 1);
        printf("%s\n", (Mix_PlayingMusic() == 0) ? "Ainda sem musica" : path.c_str());
    }
}

void
SDL2Kernel::stop_audio()
{
    Mix_HaltMusic();
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
                            KeyboardEvent::Key::SPACE,
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

Texture *
SDL2Kernel::load_texture(const Canvas* c, const string& filepath)
{
    const SDL2Canvas *canvas = dynamic_cast<const SDL2Canvas *>(c);
    SDL_Renderer *renderer = canvas->renderer();

    SDL_Texture *texture = IMG_LoadTexture(renderer, filepath.c_str());
    int w, h;

    int rc = SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);

    if (rc)
        throw Exception(SDL_GetError());

    SDL2Texture *t = new SDL2Texture(texture, w, h);
    return t;
}

