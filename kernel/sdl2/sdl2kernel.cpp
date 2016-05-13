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

#include <map>

using std::map;
using namespace ijengine;

void init_table();

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


static bool was_init = false;
static map<int, KeyboardEvent::Key> m_key_table;

static KeyboardEvent::Modifier
key_modifier(Uint16 modifier)
{
    switch (modifier)
    {
    case KMOD_CAPS:
        return KeyboardEvent::CAPS;

    case KMOD_SHIFT:
        return KeyboardEvent::SHIFT;

    case KMOD_ALT:
        return KeyboardEvent::ALT;

    case KMOD_CTRL:
        return KeyboardEvent::CONTROL;

    default:
        return KeyboardEvent::NONE;
    }
}

void init_table()
{
    m_key_table[SDLK_BACKSPACE] = KeyboardEvent::BACKSPACE;
    m_key_table[SDLK_TAB] = KeyboardEvent::TAB;
    m_key_table[SDLK_CLEAR] = KeyboardEvent::CLEAR;
    m_key_table[SDLK_RETURN] = KeyboardEvent::RETURN;
    m_key_table[SDLK_PAUSE] = KeyboardEvent::PAUSE;
    m_key_table[SDLK_ESCAPE] = KeyboardEvent::ESCAPE;
    m_key_table[SDLK_SPACE] = KeyboardEvent::SPACE;
    m_key_table[SDLK_EXCLAIM] = KeyboardEvent::EXCLAIM;
    m_key_table[SDLK_QUOTEDBL] = KeyboardEvent::DOUBLE_QUOTE;
    m_key_table[SDLK_HASH] = KeyboardEvent::HASH;
    m_key_table[SDLK_DOLLAR] = KeyboardEvent::DOLLAR;

    m_key_table[SDLK_AMPERSAND] = KeyboardEvent::AMPERSAND;
    m_key_table[SDLK_QUOTE] = KeyboardEvent::QUOTE;
    m_key_table[SDLK_LEFTPAREN] = KeyboardEvent::LEFT_PARENTESIS;
    m_key_table[SDLK_RIGHTPAREN] = KeyboardEvent::RIGHT_PARENTESIS;
    m_key_table[SDLK_ASTERISK] = KeyboardEvent::ASTERISK;
    m_key_table[SDLK_PLUS] = KeyboardEvent::PLUS;
    m_key_table[SDLK_COMMA] = KeyboardEvent::COMMA;
    m_key_table[SDLK_MINUS] = KeyboardEvent::MINUS;
    m_key_table[SDLK_PERIOD] = KeyboardEvent::PERIOD;
    m_key_table[SDLK_SLASH] = KeyboardEvent::SLASH;

    m_key_table[SDLK_0] = KeyboardEvent::ZERO;
    m_key_table[SDLK_1] = KeyboardEvent::ONE;
    m_key_table[SDLK_2] = KeyboardEvent::TWO;
    m_key_table[SDLK_3] = KeyboardEvent::THREE;
    m_key_table[SDLK_4] = KeyboardEvent::FOUR;
    m_key_table[SDLK_5] = KeyboardEvent::FIVE;
    m_key_table[SDLK_6] = KeyboardEvent::SIX;
    m_key_table[SDLK_7] = KeyboardEvent::SEVEN;
    m_key_table[SDLK_8] = KeyboardEvent::EIGHT;
    m_key_table[SDLK_9] = KeyboardEvent::NINE;
    m_key_table[SDLK_COLON] = KeyboardEvent::COLON;
    m_key_table[SDLK_SEMICOLON] = KeyboardEvent::SEMICOLON;
    m_key_table[SDLK_LESS] = KeyboardEvent::LESS;
    m_key_table[SDLK_EQUALS] = KeyboardEvent::EQUALS;
    m_key_table[SDLK_GREATER] = KeyboardEvent::GREATER;

    m_key_table[SDLK_QUESTION] = KeyboardEvent::QUESTION;
    m_key_table[SDLK_AT] = KeyboardEvent::AT;
    m_key_table[SDLK_LEFTBRACKET] = KeyboardEvent::LEFT_BRACKET;
    m_key_table[SDLK_BACKSLASH] = KeyboardEvent::BACKSLASH;
    m_key_table[SDLK_RIGHTBRACKET] = KeyboardEvent::RIGHT_BRACKET;
    m_key_table[SDLK_CARET] = KeyboardEvent::CARET;
    m_key_table[SDLK_UNDERSCORE] = KeyboardEvent::UNDERSCORE;
    m_key_table[SDLK_BACKQUOTE] = KeyboardEvent::BACKQUOTE;
    m_key_table[SDLK_DELETE] = KeyboardEvent::DELETE;

    m_key_table[SDLK_a] = KeyboardEvent::A;
    m_key_table[SDLK_b] = KeyboardEvent::B;
    m_key_table[SDLK_c] = KeyboardEvent::C;
    m_key_table[SDLK_d] = KeyboardEvent::D;
    m_key_table[SDLK_e] = KeyboardEvent::E;
    m_key_table[SDLK_f] = KeyboardEvent::F;
    m_key_table[SDLK_g] = KeyboardEvent::G;
    m_key_table[SDLK_h] = KeyboardEvent::H;
    m_key_table[SDLK_i] = KeyboardEvent::I;
    m_key_table[SDLK_j] = KeyboardEvent::J;
    m_key_table[SDLK_k] = KeyboardEvent::K;
    m_key_table[SDLK_l] = KeyboardEvent::L;
    m_key_table[SDLK_m] = KeyboardEvent::M;
    m_key_table[SDLK_n] = KeyboardEvent::N;
    m_key_table[SDLK_o] = KeyboardEvent::O;
    m_key_table[SDLK_p] = KeyboardEvent::P;
    m_key_table[SDLK_q] = KeyboardEvent::Q;
    m_key_table[SDLK_r] = KeyboardEvent::R;
    m_key_table[SDLK_s] = KeyboardEvent::S;
    m_key_table[SDLK_t] = KeyboardEvent::T;
    m_key_table[SDLK_u] = KeyboardEvent::U;
    m_key_table[SDLK_v] = KeyboardEvent::V;
    m_key_table[SDLK_w] = KeyboardEvent::W;
    m_key_table[SDLK_x] = KeyboardEvent::X;
    m_key_table[SDLK_y] = KeyboardEvent::Y;
    m_key_table[SDLK_z] = KeyboardEvent::Z;

    m_key_table[SDLK_LEFT] = KeyboardEvent::LEFT;
    m_key_table[SDLK_RIGHT] = KeyboardEvent::RIGHT;
    m_key_table[SDLK_UP] = KeyboardEvent::UP;
    m_key_table[SDLK_DOWN] = KeyboardEvent::DOWN;

    m_key_table[SDLK_F1] = KeyboardEvent::F1;
    m_key_table[SDLK_F2] = KeyboardEvent::F2;
    m_key_table[SDLK_F3] = KeyboardEvent::F3;
    m_key_table[SDLK_F4] = KeyboardEvent::F4;
    m_key_table[SDLK_F5] = KeyboardEvent::F5;
    m_key_table[SDLK_F6] = KeyboardEvent::F6;
    m_key_table[SDLK_F7] = KeyboardEvent::F7;
    m_key_table[SDLK_F8] = KeyboardEvent::F8;
    m_key_table[SDLK_F9] = KeyboardEvent::F9;
    m_key_table[SDLK_F10] = KeyboardEvent::F10;
    m_key_table[SDLK_F11] = KeyboardEvent::F11;
    m_key_table[SDLK_F12] = KeyboardEvent::F12;
}


list<event_t>
SDL2Kernel::pending_events(unsigned now)
{
    if (not was_init)
    {
        init_table();
        was_init = true;
    }

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
            {
                auto p = KeyboardEvent(timestamp,
                    KeyboardEvent::State::PRESSED,
                    m_key_table[event.key.keysym.sym],   
                    key_modifier(event.key.keysym.mod));

                events.push_back(event_t(timestamp, p.serialize()));
            }
            break;

        case SDL_KEYUP:
            {
                auto p = KeyboardEvent(timestamp,
                    KeyboardEvent::State::RELEASED,
                    m_key_table[event.key.keysym.sym],   
                    key_modifier(event.key.keysym.mod));

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

