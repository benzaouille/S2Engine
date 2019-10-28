#include "Memory/Memory.h"

namespace Memory
{
  Memory::Memory(std::size_t sizeBytesAllocator, const std::string& nameAlloc)
  {
     _sizeBytesAllocator = sizeBytesAllocator;
     _usedAlloc          = static_cast<std::size_t>(0);
     setNameAllocator(nameAlloc);
   }

   void Memory::setNameAllocator(const std::string& nameAlloc)
   {
     _nameAlloc = nameAlloc;
   }

   std::string Memory::getNameMemory() const
   {
     return _nameAlloc;
   }
}
