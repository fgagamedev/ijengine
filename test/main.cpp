#include "exception.h"
#include "engine.h"
#include "game.h"
#include "game_event.h"

#include <iostream>

using namespace ijengine;
using namespace std;

int main()
{
    int rc;

    try
    {
        GameEvent event(1);

        event.set_property<int>("valor", 10);
        cout << "valor = " << event.get_property<int>("valor");

        Engine engine;
        Game game("Teste", 640, 480);
        rc = game.run("red");
    } catch (Exception& ex)
    {
        cout << ex.what() << endl;
    }

    return rc;
}
