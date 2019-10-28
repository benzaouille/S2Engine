#ifndef MEMORY_MANAGER_H_
#define MEMORY_MANAGER_H_

#include "iostream"
#include "Core/Singleton.h"
#include "map"
#include "string"
#include "Memory/Memory.h"

namespace Manager
{
  class MemoryManager : public Core::Singleton<MemoryManager>
  {
  public:
    MemoryManager     (){}
    ~MemoryManager    (){}

    void addMemoryAllocator                                   (std::unique_ptr<Memory::Memory>&& instance);
    void setMemoryAllocator                                   (const std::string& memoryName);
    const std::unique_ptr<Memory::Memory>& currentAllocator   () {return _currentInstance;} //obliger de mettre un move contructors


    //TODO creaton des stack pool etc...
    void startUp      ();
    void shutDown     ();



  private:
      std::map<std::string, std::unique_ptr<Memory::Memory>> _instanceMap;
      std::unique_ptr<Memory::Memory> _currentInstance = nullptr;
  };
};

#endif // MEMORY_MANAGER_H_
