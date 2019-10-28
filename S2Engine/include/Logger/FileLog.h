#ifndef FILE_LOG_H_
#define FILE_LOG_H_

#include"Logger/Logger.h"
#include"fstream"
namespace Logger
{
  class FileLog : public Logger
  {
  public:
    FileLog                 (const std::string& nameLog, const std::string& nameOutput);
    FileLog                 (const std::string&& nameLog, const std::string&& nameOutput);
    ~FileLog                ();

    virtual void write      (const std::string& strLog);

  private:
    std::string       _nameOutput; //the name of the real _nameOutput.txt
    std::ofstream     _streamLog;
  };
}

#endif //FILE_LOG_H_
