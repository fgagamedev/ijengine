#include "keyboard_input.h"

#include <map>

using std::map;

namespace ijengine
{
    /*static bool was_init = false;
    static map<int, KeyboardInput::Key> m_key_table;

    static KeyboardInput::Modifier
    key_modifier(Uint16 modifier)
    {
        switch (modifier)
        {
        case KMOD_CAPS:
            return KeyboardInput::CAPS;

        case KMOD_SHIFT:
            return KeyboardInput::SHIFT;

        case KMOD_ALT:
            return KeyboardInput::ALT;

        case KMOD_CTRL:
            return KeyboardInput::CONTROL;

        default:
            return KeyboardInput::NONE;
        }
    }

    void init_table()
    {
        m_key_table[SDLK_BACKSPACE] = KeyboardInput::BACKSPACE;
        m_key_table[SDLK_TAB] = KeyboardInput::TAB;
        m_key_table[SDLK_CLEAR] = KeyboardInput::CLEAR;
        m_key_table[SDLK_RETURN] = KeyboardInput::RETURN;
        m_key_table[SDLK_PAUSE] = KeyboardInput::PAUSE;
        m_key_table[SDLK_ESCAPE] = KeyboardInput::ESCAPE;
        m_key_table[SDLK_SPACE] = KeyboardInput::SPACE;
        m_key_table[SDLK_EXCLAIM] = KeyboardInput::EXCLAIM;
        m_key_table[SDLK_QUOTEDBL] = KeyboardInput::DOUBLE_QUOTE;
        m_key_table[SDLK_HASH] = KeyboardInput::HASH;
        m_key_table[SDLK_DOLLAR] = KeyboardInput::DOLLAR;

        m_key_table[SDLK_AMPERSAND] = KeyboardInput::AMPERSAND;
        m_key_table[SDLK_QUOTE] = KeyboardInput::QUOTE;
        m_key_table[SDLK_LEFTPAREN] = KeyboardInput::LEFT_PARENTESIS;
        m_key_table[SDLK_RIGHTPAREN] = KeyboardInput::RIGHT_PARENTESIS;
        m_key_table[SDLK_ASTERISK] = KeyboardInput::ASTERISK;
        m_key_table[SDLK_PLUS] = KeyboardInput::PLUS;
        m_key_table[SDLK_COMMA] = KeyboardInput::COMMA;
        m_key_table[SDLK_MINUS] = KeyboardInput::MINUS;
        m_key_table[SDLK_PERIOD] = KeyboardInput::PERIOD;
        m_key_table[SDLK_SLASH] = KeyboardInput::SLASH;

        m_key_table[SDLK_0] = KeyboardInput::ZERO;
        m_key_table[SDLK_1] = KeyboardInput::ONE;
        m_key_table[SDLK_2] = KeyboardInput::TWO;
        m_key_table[SDLK_3] = KeyboardInput::THREE;
        m_key_table[SDLK_4] = KeyboardInput::FOUR;
        m_key_table[SDLK_5] = KeyboardInput::FIVE;
        m_key_table[SDLK_6] = KeyboardInput::SIX;
        m_key_table[SDLK_7] = KeyboardInput::SEVEN;
        m_key_table[SDLK_8] = KeyboardInput::EIGHT;
        m_key_table[SDLK_9] = KeyboardInput::NINE;
        m_key_table[SDLK_COLON] = KeyboardInput::COLON;
        m_key_table[SDLK_SEMICOLON] = KeyboardInput::SEMICOLON;
        m_key_table[SDLK_LESS] = KeyboardInput::LESS;
        m_key_table[SDLK_EQUALS] = KeyboardInput::EQUALS;
        m_key_table[SDLK_GREATER] = KeyboardInput::GREATER;

        m_key_table[SDLK_QUESTION] = KeyboardInput::QUESTION;
        m_key_table[SDLK_AT] = KeyboardInput::AT;
        m_key_table[SDLK_LEFTBRACKET] = KeyboardInput::LEFT_BRACKET;
        m_key_table[SDLK_BACKSLASH] = KeyboardInput::BACKSLASH;
        m_key_table[SDLK_RIGHTBRACKET] = KeyboardInput::RIGHT_BRACKET;
        m_key_table[SDLK_CARET] = KeyboardInput::CARET;
        m_key_table[SDLK_UNDERSCORE] = KeyboardInput::UNDERSCORE;
        m_key_table[SDLK_BACKQUOTE] = KeyboardInput::BACKQUOTE;
        m_key_table[SDLK_DELETE] = KeyboardInput::DELETE;

        m_key_table[SDLK_a] = KeyboardInput::A;
        m_key_table[SDLK_b] = KeyboardInput::B;
        m_key_table[SDLK_c] = KeyboardInput::C;
        m_key_table[SDLK_d] = KeyboardInput::D;
        m_key_table[SDLK_e] = KeyboardInput::E;
        m_key_table[SDLK_f] = KeyboardInput::F;
        m_key_table[SDLK_g] = KeyboardInput::G;
        m_key_table[SDLK_h] = KeyboardInput::H;
        m_key_table[SDLK_i] = KeyboardInput::I;
        m_key_table[SDLK_j] = KeyboardInput::J;
        m_key_table[SDLK_k] = KeyboardInput::K;
        m_key_table[SDLK_l] = KeyboardInput::L;
        m_key_table[SDLK_m] = KeyboardInput::M;
        m_key_table[SDLK_n] = KeyboardInput::N;
        m_key_table[SDLK_o] = KeyboardInput::O;
        m_key_table[SDLK_p] = KeyboardInput::P;
        m_key_table[SDLK_q] = KeyboardInput::Q;
        m_key_table[SDLK_r] = KeyboardInput::R;
        m_key_table[SDLK_s] = KeyboardInput::S;
        m_key_table[SDLK_t] = KeyboardInput::T;
        m_key_table[SDLK_u] = KeyboardInput::U;
        m_key_table[SDLK_v] = KeyboardInput::V;
        m_key_table[SDLK_w] = KeyboardInput::W;
        m_key_table[SDLK_x] = KeyboardInput::X;
        m_key_table[SDLK_y] = KeyboardInput::Y;
        m_key_table[SDLK_z] = KeyboardInput::Z;

        m_key_table[SDLK_LEFT] = KeyboardInput::LEFT;
        m_key_table[SDLK_RIGHT] = KeyboardInput::RIGHT;
        m_key_table[SDLK_UP] = KeyboardInput::UP;
        m_key_table[SDLK_DOWN] = KeyboardInput::DOWN;

        m_key_table[SDLK_F1] = KeyboardInput::F1;
        m_key_table[SDLK_F2] = KeyboardInput::F2;
        m_key_table[SDLK_F3] = KeyboardInput::F3;
        m_key_table[SDLK_F4] = KeyboardInput::F4;
        m_key_table[SDLK_F5] = KeyboardInput::F5;
        m_key_table[SDLK_F6] = KeyboardInput::F6;
        m_key_table[SDLK_F7] = KeyboardInput::F7;
        m_key_table[SDLK_F8] = KeyboardInput::F8;
        m_key_table[SDLK_F9] = KeyboardInput::F9;
        m_key_table[SDLK_F10] = KeyboardInput::F10;
        m_key_table[SDLK_F11] = KeyboardInput::F11;
        m_key_table[SDLK_F12] = KeyboardInput::F12;
    }
    */

    KeyboardInput::KeyboardInput(State s, Key k, Modifier m, unsigned t)
        : m_state(s), m_key(k), m_modifier(m), m_timestamp(t)
    {
    }

    KeyboardInput::State
    KeyboardInput::state() const
    {
        return m_state;
    }

    KeyboardInput::Key
    KeyboardInput::key() const
    {
        return m_key;
    }

    KeyboardInput::Modifier
    KeyboardInput::modifier() const
    {
        return m_modifier;
    }


    unsigned
    KeyboardInput::timestamp() const
    {
        return m_timestamp;
    }

/*    KeyboardInput
    KeyboardInput::from_SDL(const SDL_Input& event)
    {
        if (not was_init)
        {
            init_table();
            was_init = true;
        }

        KeyboardInput::State state = (event.type == SDL_KEYDOWN ?
            KeyboardInput::PRESSED : KeyboardInput::RELEASED);
        KeyboardInput::Key key = m_key_table[event.key.keysym.sym];
        KeyboardInput::Modifier modifier = key_modifier(event.key.keysym.mod);

        return KeyboardInput(state, key, modifier);
    } */
}
