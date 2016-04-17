#ifndef SDL3DVIDEO_H
#define SDL3DVIDEO_H

#include "video.h"
#include <SDL2/SDL.h>

namespace ijengine {

    class SDL3DVideo : public Video {
    public:
        SDL3DVideo();
        ~SDL3DVideo();

        Window * create_window(int w, int h);
    };

}

#endif
