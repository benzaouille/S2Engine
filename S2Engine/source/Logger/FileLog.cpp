#include "Logger/FileLog.h"

namespace Logger
{
  FileLog::FileLog(const std::string& nameLog, const std::string& nameOutput):
  Logger(nameLog)
  {
    _nameOutput = nameOutput;

    try
    {
      _streamLog.open(nameOutput);
      if(!_streamLog.is_open())
      {
          throw std::string("IMPOSSIBLE DE CREER LE FICHIER LOG " + nameOutput);
      }
    }
    catch(const std::string& erreur)
    {
      std::cerr << erreur << std::endl;
    }

  }

  FileLog::FileLog(const std::string&& nameLog, const std::string&& nameOutput):
  Logger(nameLog)
  {
    _nameOutput = nameOutput;
    _streamLog.open(nameOutput);
  }

  void FileLog::write(const std::string& strLog)
  {
    _streamLog << strLog << "\n";
  }

  FileLog::~FileLog()
  {
    _streamLog << "CLOSING THE LOG... " << _nameOutput;
    _streamLog.close();
  }
}
