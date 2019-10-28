#include "Memory/StackAllocator.h"


namespace Memory
{
    StackAllocator::StackAllocator(const std::size_t size, const Marker start, const std::string& nameAlloc):
    Memory(size, nameAlloc),
    _start(start),
    _allocationCpt(0)
    {
      _currentMarker = _start;
    }

    StackAllocator::StackAllocator(const std::size_t size, const Marker start, const std::string&& nameAlloc):
    Memory(size, nameAlloc),
    _start(start),
    _allocationCpt(0)
    {
      _currentMarker = _start;
    }



    StackAllocator::~StackAllocator()
    {
      _currentMarker = _start;

    }

    Marker StackAllocator::getCurrentMarker() const
    {
      return _currentMarker;
    }

    Marker StackAllocator::Allocate(const std::size_t bytes)
    {
      //TODO
      //alignement optimisation..
      //Tracking bug with log manager...
      _usedAlloc       += bytes;
      if(_usedAlloc > _sizeBytesAllocator)
      {
        //TODO
        std::cerr << "Allocation memory overflow" << std::endl;
      }
      Marker oldMarker  = _currentMarker;
      _currentMarker   += bytes;

      return static_cast<Marker>(oldMarker);
    }


    void StackAllocator::Free(const Marker marker)
    {
      //TODO
      //bound checking pour voir si marker est dans la zone de memoire alloué
      UPTR start          = reinterpret_cast<UPTR>(_start);
      UPTR end            = reinterpret_cast<UPTR>(_start + _sizeBytesAllocator);
      UPTR memoryCaseNbr  = reinterpret_cast<UPTR>(marker);
      if(memoryCaseNbr >= start && memoryCaseNbr < end)
      {
          _currentMarker = marker;
      }
      else
      {
        //TODO
        //ERROR pck on est en dehors de la zone de la mémoire allouée
        std::cerr << "Freeing overflow" << std::endl;
      }
    }
}
