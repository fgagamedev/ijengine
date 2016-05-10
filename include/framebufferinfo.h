#ifndef IJENGINE_FRAMEINFO_H
#define IJENGINE_FRAMEINFO_H


#include <SDL2/SDL.h>
//ContextInfo.h
namespace ijengine{
 
  struct FramebufferInfo{
 
    unsigned int flags;
    int rbuffer = 5;
    int gbuffer = 5;
    int bbuffer = 5;
    int depthsize = 16;
    int doublebuffersize = 1;
 
    FramebufferInfo()
    {
      //default
      flags = SDL_WINDOW_OPENGL;
      rbuffer = 5;
      gbuffer = 5;
      bbuffer = 5;
   	  depthsize = 16;
      doublebuffersize = 1;
    }
 
    FramebufferInfo(int r_buffer_size, int g_buffer_size,int b_buffer_size, int depth_size, int double_buffer_size)
    {
   	  rbuffer = r_buffer_size;
      gbuffer = g_buffer_size;
      bbuffer = b_buffer_size;
   	  depthsize = depth_size;
      doublebuffersize = double_buffer_size;
  }
 
   //(optional)implement copy constructor and assignment operator
 };
}

#endif
