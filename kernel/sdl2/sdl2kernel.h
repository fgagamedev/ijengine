#ifndef IJENGINE_SDL2_KERNEL_H
#define IJENGINE_SDL2_KERNEL_H

#include "kernel.h"
#include "time.h"

using namespace ijengine;

class SDL2Kernel : public Kernel {
public:
    SDL2Kernel();
    ~SDL2Kernel();
    
    Window * create_window(const string& title, int w, int h);

    void play_audio_from_path(const string& title);
    void stop_audio();

    list<event_t> pending_events(unsigned now);

    unsigned time_elapsed();
    void pause_timer();
    void resume_timer();

    Texture * load_texture(const Canvas* canvas, const string& filepath);

protected:
    Time *m_timer;
};

#endif
