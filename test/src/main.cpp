#include <ijengine/exception.h>
#include "test_game.h"
#include <iostream>

using namespace ijengine;
using namespace std;

int main()
{
    int rc;

    try
    {
        TestGame game("Teste", 640, 480);
        rc = game.run("red");
    } catch (Exception& ex)
    {
        cout << ex.what() << endl;
    }

    return rc;
}
