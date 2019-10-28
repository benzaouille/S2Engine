//S2ENGINE ENTRY POINT
//BY SOOF
#include<iostream>
#include "Manager/EnvironmentManager.h"
#include "Manager/LoggerManager.h"
#include "Manager/MemoryManager.h"
#include "Logger/FileLog.h"
#include "MEmory/StackAllocator.h"
#include <ctime> // for the comparaison with the stack
#include <memory>

int main(int argc, char** argv)
{

  std::cout << "S2ENGINE RUNNING" << std::endl;
  //MANAGER ENVIRONMENT
  Manager::EnvironmentManager&  envManger      = Manager::EnvironmentManager::getInstance();

  //MANAGER LOGGER
  Manager::LoggerManager&       LogManager    = Manager::LoggerManager::getInstance();
  std::shared_ptr<Logger::FileLog> fileLog1 (new Logger::FileLog("fileLog1", "Output1.txt"));
  Manager::LoggerManager::getInstance().addLogger(fileLog1);
  Manager::LoggerManager::getInstance().setLogger("fileLog1");
  Manager::LoggerManager::getInstance() << "FILELOG1";

  //MANAGER CUSTOM ALLOCATOR
  Manager::MemoryManager&      MemManager  = Manager::MemoryManager::getInstance();
  //test pour le stack ALLOCATOR
  int size = 100;
  U8* ptr = static_cast<U8*>(malloc(size));
  std::unique_ptr<Memory::Memory> stackAlloc( new Memory::StackAllocator(size, ptr, "stack"));
  Manager::MemoryManager::getInstance().addMemoryAllocator(std::move(stackAlloc));
  free(ptr);
}
