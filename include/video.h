#ifndef VIDEO_H
#define VIDEO_H

namespace ijengine {

    class Window;

    class Video {
    public:
        virtual ~Video() = default;
        virtual Window * create_window(int w, int h) = 0;
    };

}

#endif
