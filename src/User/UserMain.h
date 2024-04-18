#pragma once

#include "import.h"
#include "UserContext.h"

class UserMain {
public:
    UserContext* ctx;

public:
    UserMain();
    ~UserMain();
    void OnStart();
    void OnLogicUpdate(float dt);
    void OnReadyDraw();
    void OnQuit();

protected:
    float restTime;
    void OnFixLogicUpdate(float fixdt);
};