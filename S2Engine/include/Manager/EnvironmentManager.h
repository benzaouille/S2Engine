#ifndef ENVIRONMENT_MANAGER_H_
#define ENVIRONMENT_MANAGER_H_

#include<iostream>
#include "Core/Singleton.h"
//OS detection



namespace Manager
{
  #ifdef _WIN32
        //define something for Windows (32-bit and 64-bit, this part is common)
     #ifdef _WIN64
        //define something for Windows (64-bit only)
        #define environment_0S(){ printf("S2Engine running on WINDOW 64-bit\n");}
     #else
        //define something for Windows (32-bit only)
        #define environment_0S(){ printf("S2Engine running on WINDOW 32-bit\n");}
     #endif
  #elif __APPLE__
        #define environment_0S(){ printf("S2Engine running on MAC OS\n");}
  #endif

  #if __cplusplus >= 201103L
    #define I8 int8_t
    #define I16 int16_t
    #define I32 int32_t
    #define I64 int64_t

    #define U8 uint8_t
    #define U16 uint16_t
    #define U32 uint32_t
    #define U64 uint64_t

    #define UPTR uintptr_t // uint capable of holfing ptr
#endif

  class EnvironmentManager : public Core::Singleton<EnvironmentManager>
  {
  public:
    EnvironmentManager(){}
    ~EnvironmentManager();
    void startUp();
    void shutDown();
  };
};


#endif //ENVIRONMENT_MANAGER_H_
