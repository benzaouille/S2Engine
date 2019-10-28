#include "Manager/EnvironmentManager.h"

namespace Manager
{
  void EnvironmentManager::startUp()
  {
    //output the os in the standard ouput..
    environment_0S();
  }

  void EnvironmentManager::shutDown()
  {
    std::cout << "S2Engine Shut Down" << std::endl;
  }

  EnvironmentManager::~EnvironmentManager()
  {
    shutDown();
  }


}
