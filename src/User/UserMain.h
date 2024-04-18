#pragma once

#include "import.h"

class UserMain {
  public:
    void OnStart();
    void OnLogicUpdate(float dt);
    void OnQuit();

  protected:
    float restTime;
    void OnFixLogicUpdate(float fixdt);
};