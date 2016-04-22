#include "level.h"
#include "test_level.h"

namespace ijengine {

    Level *
    Level::load(const string& level)
    {
        if (level == "red")
            return new TestLevel(255, 0, 0, "green");
        else if (level == "green")
            return new TestLevel(0, 255, 0, "blue");
        else if (level == "blue")
            return new TestLevel(0, 0, 255);
        else
            return nullptr;
    }
}
