#include "Manager/MemoryManager.h"

namespace Manager
{
  void MemoryManager::startUp()
  {

  }


  void MemoryManager::shutDown()
  {

  }


  void MemoryManager::addMemoryAllocator(std::unique_ptr<Memory::Memory>&& instance)
  {
    _instanceMap.insert(std::make_pair(instance->getNameMemory(), std::move(instance)));
  }


  void MemoryManager::setMemoryAllocator(const std::string& memoryName)
  {
      decltype(_instanceMap)::iterator it = _instanceMap.find(memoryName);
      //on remet l'allocator une fois qu'on veut plus l'utilisé
      if(_currentInstance != nullptr)
      {
          addMemoryAllocator(std::move(_currentInstance));
          if(it != _instanceMap.end())
          {
            _currentInstance = std::move(it->second);
          }
          else
          {
            std::cerr << "ERROR WRONG MEMORY NAME" << std::endl;
          }
      }
      else
      {
        std::cerr << "NO MEMEORY ALLOCATOR IN THE MAP" << std::endl;
      }
  }


}
