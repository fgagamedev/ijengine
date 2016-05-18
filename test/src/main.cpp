#include <ijengine/exception.h>
#include "test_game.h"
#include <iostream>

#include <ijengine/rectangle.h>

using namespace ijengine;
using namespace std;

int main()
{
    Rectangle A(0, 0, 10, 10);
    Rectangle B(5, 0, 10, 10);

    auto r = A.intersection(B);

    printf("R = (%.2lf, %.2lf), dims = (%.2lf, %.2lf)\n", r.x(), r.y(), r.w(), r.h());
/*    int rc;

    try
    {
        TestGame game("Teste", 640, 480);
        rc = game.run("red");
    } catch (Exception& ex)
    {
        cout << ex.what() << endl;
    } 

    return rc;*/
    return 0;
}
