#include "exception.h"
#include "engine.h"
#include "kernel.h"
#include "lib.h"
#include "os.h"
#include "event.h"
#include "game_event.h"
#include "level_factory.h"
#include "events_translator.h"
#include "game_events_listener.h"

#include <stdio.h>
#include <list>
#include <utility>

using std::pair;
using std::list;

namespace ijengine 
{
    static Kernel *kernel = nullptr;
    
    Engine::Engine()
    {
        auto files = os::list_files("libs");
        string path("");
        
        for (auto file : files)
            if (file.find("kernel") != string::npos) 
            {
                path = "libs/" + file;
                break;
            }
            
        if (path.size() == 0)
            throw Exception("Kernel not found in libs dir");
            
        m_kernel_lib = unique_ptr<Lib>(os::load_lib(path));
        
        if (not m_kernel_lib)
            throw Exception("Can't load kernel lib");
            
        auto sym = m_kernel_lib->symbol("create_kernel");
                          
        if (not sym)
            throw Exception("Invalid kernel: missing create_kernel()");
            
        Kernel * (*create)();
        *reinterpret_cast<void **>(&create) = sym;
        
        kernel = create();
        
        if (not kernel)
            throw Exception("Can't create the kernel");
    }
    
    Engine::~Engine()
    {
        auto sym = m_kernel_lib->symbol("destroy_kernel");
                          
        if (not sym)
            throw Exception("Invalid kernel: missing destroy_kernel()");
            
        void (*destroy)(Kernel *);
        *reinterpret_cast<void **>(&destroy) = sym;
        
        destroy(kernel);
    }
    
    namespace video 
    {
        Window *
        create_window(const string& title, int w, int h)
        {
            return kernel->create_window(title, w, h);
        }
    }

    namespace event
    {
        static list<const EventsTranslator *> translators;
        static list<GameEventsListener *> listeners;

        void
        dispatch_pending_events(unsigned now)
        {
            auto events = kernel->pending_events(now);

            if (events.empty())
                return;

            list<game_event_t> game_events;

            for (auto translator : translators)
            {
                auto more = translator->translate(events);
                game_events.merge(more);

                if (events.empty())
                    break;
            }

            for (auto event : game_events)
            {
                GameEvent game_event = GameEvent::deserialize(event.second,
                    event.first);

                for (auto listener : listeners)
                    if (listener->on_event(game_event))
                        break;
            }
        }

        void
        register_translator(const EventsTranslator *translator)
        {
            if (translator) translators.push_back(translator);
        }

        void
        unregister_translator(const EventsTranslator *translator)
        {
            if (translator) translators.remove(translator);
        }

        void
        register_listener(GameEventsListener *listener)
        {
            if (listener) listeners.push_back(listener);
        }

        void unregister_listener(GameEventsListener *listener)
        {
            if (listener) listeners.remove(listener);
        }
    }

    namespace time
    {
        unsigned
        time_elapsed()
        {
            return kernel->time_elapsed();
        }

        void
        pause()
        {
            kernel->pause_timer();
        }

        void
        resume()
        {
            kernel->resume_timer();
        }
    }

    namespace level
    {
        static LevelFactory *level_factory = nullptr;

        void
        register_factory(LevelFactory *factory)
        {
            level_factory = factory;
        }

        void unregister_factory()
        {
            level_factory = nullptr;
        }

        Level *
        make(const string& level_id)
        {
            return level_factory ? level_factory->make_level(level_id) : nullptr;
        }

        void
        release(Level *level)
        {
            if (level_factory)
                level_factory->release(level);
        }
    }
}
