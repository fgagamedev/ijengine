#include "exception.h"
#include "engine.h"
#include "kernel.h"
#include "lib.h"
#include "os.h"
#include "event.h"
#include "game_event.h"
#include "events_translator.h"

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

        void
        dispatch_pending_events(unsigned now)
        {
            auto events = kernel->pending_events(now);

            if (events.empty())
                return;

            for (auto event : events)
                printf("event on %u: [%s]\n", event.first, event.second.c_str());

            list<game_event_t> game_events;

            for (auto translator : translators)
            {
printf("Translating...\n");
                auto more = translator->translate(events);

            for (auto ge : more)
                printf("more event on %u: [%s]\n", ge.first, ge.second.serialize().c_str());
                game_events.splice(game_events.end(), more);

                if (events.empty())
                    break;
            }

            for (auto ge : game_events)
                printf("event on %u: [%s]\n", ge.first, ge.second.serialize().c_str());
                
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
    }
}
