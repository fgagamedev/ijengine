#ifndef IJENGINE_KEYBOARD_INPUT_H
#define IJENGINE_KEYBOARD_INPUT_H

namespace ijengine {

    static const unsigned char KEYBOARD_INPUT = 0x02;

    struct _KeyboardInput
    {
        typedef enum {PRESSED, RELEASED} State;

        typedef
        enum {
            BACKSPACE, TAB, CLEAR, RETURN, PAUSE, ESCAPE, SPACE, EXCLAIM,
            DOUBLE_QUOTE, HASH, DOLLAR, AMPERSAND, QUOTE, LEFT_PARENTESIS,
            RIGHT_PARENTESIS, ASTERISK, PLUS, COMMA, MINUS, PERIOD, SLASH, ZERO,
            ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, COLON, SEMICOLON,
            LESS, EQUALS, GREATER, QUESTION, AT, LEFT_BRACKET, BACKSLASH,
            RIGHT_BRACKET, CARET, UNDERSCORE, BACKQUOTE, DELETE, A, B, C, D, E, F,
            G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, LEFT,
            RIGHT, UP, DOWN, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12
             } Key;

        typedef enum {NONE, SHIFT, CONTROL, ALT, CAPS} Modifier;

        _KeyboardInput(State s, Key k, Modifier m) :
            type(KEYBOARD_INPUT), state(s), key(k), modifier(m) {}

        unsigned char type;
        unsigned char state;
        unsigned char key;
        unsigned char modifier;
    };

    typedef struct _KeyboardInput KeyboardInput;
}

#endif
