#ifndef IJENGINE_GAME_H
#define IJENGINE_GAME_H

#include <string>

using std::string;

namespace ijengine {

    class Level;

    class Game {
    public:
        Game(const string& title, int w = 800, int h = 600);

        int run(const string& level_id);

    private:
        string m_title;
        int m_w, m_h;
    };

}

#endif
