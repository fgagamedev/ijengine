#ifndef IJENGINE_CONTEXTINFO_H
#define IJENGINE_CONTEXTINFO_H



//ContextInfo.h
namespace ijengine{
 
  //OpenGL versions
  struct ContextInfo
  {
     int major_version, minor_version;
     bool core;
 
     ContextInfo()//default
     {
       major_version = 3;
       minor_version = 3;
       core = true;
     }
 
     ContextInfo(int majorversion, int minorversion, bool _core)
     {
       major_version = majorversion;
       minor_version = minorversion;
       core = _core;
     }
 
  };
}

#endif
