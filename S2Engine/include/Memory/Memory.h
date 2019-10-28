#ifndef MEMORY_H
#define MEMORY_H


#include "string"
#include "Manager/EnvironmentManager.h"

namespace Memory
{
  using  Marker = U8*;

  class Memory
  {
  public:
      Memory(std::size_t sizeBytesAllocator, const std::string& nameAlloc);

      virtual ~Memory(){};

      virtual Marker Allocate                  (const std::size_t bytes) = 0;
      virtual void Free                      (const Marker ptr) = 0;

      //
      std::string getNameMemory              () const;


    protected:
      std::size_t _usedAlloc;
      std::size_t _sizeBytesAllocator;

    private:
      //not showing to the user..
      void  setNameAllocator(const std::string& nameAlloc);
      std::string _nameAlloc;

  };
};

#endif // MEMORY_H
