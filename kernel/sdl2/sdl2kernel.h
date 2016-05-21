#ifndef IJENGINE_SDL2_KERNEL_H
#define IJENGINE_SDL2_KERNEL_H

#include "time.h"
#include "kernel.h"

#include <SDL2/SDL.h>

using namespace ijengine;

class SDL2Kernel : public Kernel {
public:
    SDL2Kernel();
    ~SDL2Kernel();
    
    Window * create_window(const string& title, int w, int h);

    void set_audio_dir(const string& dir_path);
    void play_audio_from_path(const string& title);
    void stop_audio();

    list<SystemEvent> pending_system_events(unsigned now);
//    list<event_t> pending_events(unsigned now);

    unsigned time_elapsed();
    void pause_timer();
    void resume_timer();

    Texture * load_texture(const Canvas* canvas, const string& filepath);

private:
    Time *m_timer;
    unsigned m_last_update;
    list<SDL_Event> m_events;

    void update_pending_events(unsigned now);
};

#endif
