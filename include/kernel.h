#ifndef IJENGINE_KERNEL_H
#define IJENGINE_KERNEL_H

#include "event.h"

#include <string>
#include <list>

using std::list;
using std::string;

namespace ijengine {

    class Event;
    class Window;
    class Canvas;
    class Texture;
    
    class Kernel {
    public:
        virtual ~Kernel() {}
        
        virtual Window * create_window(const string& title, int w, int h) = 0;

        virtual void set_audio_dir(const string& dir_path) = 0;
        virtual void play_audio_from_path(const string& title) = 0;
        virtual void stop_audio() = 0;

        virtual list<event_t> pending_events(unsigned now) = 0;

        virtual unsigned time_elapsed() = 0;
        virtual void pause_timer() = 0;
        virtual void resume_timer() = 0;

        virtual Texture * load_texture(const Canvas* canvas, const string& filepath) = 0;
    };
}

#endif
