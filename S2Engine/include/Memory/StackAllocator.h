#ifndef STACK_ALLOCATOR_H_
#define STACK_ALLOCATOR_H_

#include "Memory/Memory.h"
namespace Memory
{

  class StackAllocator : public Memory::Memory // pourquoi ne pas utiliser le strategy pattern plutot que de l'héritage a voir...
  {
  public:
    StackAllocator                         (const std::size_t size, const Marker start, const std::string& stackName);
    StackAllocator                         (const std::size_t size, const Marker start, const std::string&& stackName);
    ~StackAllocator                        ();

    virtual Marker Allocate                (const std::size_t bytes);
    virtual void Free                      (const Marker ptr);

    Marker getCurrentMarker                () const;
    //Pk pas objet templater .... test..
    //void    addAllocationCpt               (){_allocationCpt++;}
    //void    subAllocationCpt               (){_allocationCpt--;}

  private:
    //https://stackoverflow.com/questions/31978324/what-exactly-is-stdatomic
    std::atomic<I32>         _allocationCpt;
    const Marker             _start;
    Marker                   _currentMarker;
  };
};

#endif //STACK_ALLOCATOR_H_
