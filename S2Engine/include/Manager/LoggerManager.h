#ifndef LOGGER_MANAGER_H_
#define LOGGER_MANAGER_H_

#include "Logger/Logger.h"
#include "Core/Singleton.h"

namespace Manager
{
  class LoggerManager : public Core::Singleton<LoggerManager>
  {
  public:
    LoggerManager(){}
    ~LoggerManager(){}

    void addLogger                                  (std::shared_ptr<Logger::Logger> instance);
    void setLogger                                  (const std::string& strLogger);
    void setLogger                                  (const std::string&& strLogger);
    std::shared_ptr<Logger::Logger> currentLog      (){return _currentInstance;}

    //START & SHUT of the manager
    //TODO creaton des stack pool etc...
    void startUp();
    void shutDown();

    //C++ writing in buffer
    template<typename T>
    Logger::Logger& operator<<(const T& toLog);

  private:
      std::map<std::string ,std::shared_ptr<Logger::Logger>> _instanceMap;
      std::shared_ptr<Logger::Logger> _currentInstance = nullptr;
  };

  template<typename T>
  Logger::Logger& LoggerManager::operator<<(const T& toLog)
  {
    *_currentInstance << toLog;
    return *_currentInstance;
  }
};


#endif //LOGGER_MANAGER_H_
