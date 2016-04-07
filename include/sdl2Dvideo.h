#ifndef SDL2DVIDEO_H
#define SDL2DVIDEO_H

#include "video.h"

namespace ijengine {

    class SDL2DVideo : public Video {
    public:
        SDL2DVideo();
        ~SDL2DVideo();
        
        Window * create_window(int w, int h);
    };

}

#endif
