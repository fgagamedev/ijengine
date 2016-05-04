#include <ijengine/exception.h>
#include <ijengine/engine.h>
#include <ijengine/game.h>

#include <iostream>

using namespace ijengine;
using namespace std;

int main()
{
    int rc;

    try
    {
        Engine engine;

        Game game("Teste", 640, 480);

        rc = game.run("red");
    } catch (Exception& ex)
    {
        cout << ex.what() << endl;
    }

    return rc;
}
