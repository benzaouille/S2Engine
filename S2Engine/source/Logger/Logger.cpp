#include "Logger/Logger.h"


namespace Logger
{
  Logger::Logger(const std::string& nameLog)
  {
    setNameLog(nameLog);
  }

  void Logger::setNameLog(const std::string& nameLog)
  {
    _nameLog = nameLog;
  }

  std::string Logger::getNameLog() const
  {
    return  _nameLog;
  }
}
