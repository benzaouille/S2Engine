#ifndef ILOGGER_H_
#define ILOGGER_H_

#include<iostream>
#include <map>
#include<string>
#include<iterator>
#include <sstream>

namespace Logger
{
  class Logger
  {
    public:
      Logger                         (const std::string& nameLog);
      virtual ~Logger                (){}
      virtual void write             (const std::string& strLog) = 0;

      //Getter & setter name Log for the map in the LoggerManager object
      void setNameLog                (const std::string& nameLog);
      std::string getNameLog         () const;


      //C++ style print..
      template<typename T>
      Logger& operator<<          (const T& toLog);

    private:
      std::string       _nameLog; //for the map in the Logger Manager
  };

  template<typename T>
  Logger& Logger::operator<<(const T& toLog)
  {
    std::ostringstream flux;
    flux << toLog;
    write(flux.str());

    return *this;
  }
};


#endif // LOGGER_H_
