#ifndef IJENGINE_KERNEL_H
#define IJENGINE_KERNEL_H

#include "event.h"

#include <string>
#include <list>

using std::list;
using std::string;

namespace ijengine {

    class Window;
    class Event;
    
    class Kernel {
    public:
        virtual ~Kernel() {}
        
        virtual Window * create_window(const string& title, int w, int h) = 0;

        virtual list<event_t> pending_events(unsigned now) = 0;

        virtual unsigned time_elapsed() = 0;
        virtual void pause_timer() = 0;
        virtual void resume_timer() = 0;
    };
}

#endif
