#ifndef IJENGINE_ENGINE_H
#define IJENGINE_ENGINE_H

#include <string>
#include <memory>

using std::string;
using std::unique_ptr;

namespace ijengine {
    
    class Lib;
    class Level;
    class Window;
    class LevelFactory;
    class EventsTranslator;
    class GameEventsListener;
    
    class Engine {
    public:
        Engine();
        ~Engine();    
        
    private:
        unique_ptr<Lib> m_kernel_lib;
    };
    
    namespace video {
        Window * create_window(const string& title, int w, int h);
    }

    namespace event {
        void dispatch_pending_events(unsigned now);
        void register_translator(const EventsTranslator *translator);
        void unregister_translator(const EventsTranslator *translator);
        void register_listener(GameEventsListener *listener);
        void unregister_listener(GameEventsListener *listener);
    }

    namespace time {
        unsigned time_elapsed();
        void pause();
        void resume();
    }

    namespace level {
        void register_factory(LevelFactory *factory);
        void unregister_factory();
        Level * make(const string& level_id);
        void release(Level *level);
    }
}

#endif
