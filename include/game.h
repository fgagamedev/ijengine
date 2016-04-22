#ifndef GAME_H
#define GAME_H

#include <string>
using std::string;

namespace ijengine {

    class Canvas;
    class Level;

    class Game {
    public:
        virtual ~Game();

        int run(const string& level_id);

    protected:
        virtual Canvas * canvas() const = 0;

        void draw(Level *level, int now, int last);
    };

}

#endif
