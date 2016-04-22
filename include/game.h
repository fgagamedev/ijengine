#ifndef GAME_H
#define GAME_H

namespace ijengine {

    class Canvas;

    class Game {
    public:
        virtual ~Game();

        int run();

    protected:
        virtual Canvas * canvas() const = 0;

        void draw(int now, int last);
    };

}

#endif
