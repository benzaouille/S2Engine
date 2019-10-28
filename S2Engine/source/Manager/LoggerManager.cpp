#include "Manager/LoggerManager.h"

namespace Manager
{

  void LoggerManager::startUp()
  {

  }


  void LoggerManager::shutDown()
  {

  }


  void LoggerManager::addLogger(std::shared_ptr<Logger::Logger> instance)
  {
    _instanceMap[instance->getNameLog()] =  instance;
  }

  void LoggerManager::setLogger(const std::string& logName)
  {
    decltype(_instanceMap)::iterator it = _instanceMap.find(logName);
    if(it != _instanceMap.end())
    {
      _currentInstance = it->second;
    }
    else
    {
      //TODO par exemple un logger d'erreur ou un class error a voir..
      std::cerr << "ERROR WRONG LOGGER NAME" << std::endl;
    }
  }

  void LoggerManager::setLogger(const std::string&& logName)
  {
    decltype(_instanceMap)::iterator it = _instanceMap.find(logName);
    if(it != _instanceMap.end())
    {
      _currentInstance = it->second;
    }
    else
    {
      //TODO par exemple un logger d'erreur ou un class error a voir..
      std::cerr << "ERROR WRONG LOGGER NAME" << std::endl;
    }
  }


}
