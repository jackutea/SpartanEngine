#pragma once

#include "import.h"
#include "UserContext.h"
#include "PublishSetting.h"

class UserMain {
public:
    UserContext* ctx;

public:
    UserMain();
    ~UserMain();
    void OnStart(EngineCommand* cmd);
    void OnLogicUpdate(EngineCommand* cmd, float dt);
    void OnReadyDraw(EngineCommand* cmd);
    void OnQuit();

protected:
    float restFixTime;
    void OnFixLogicUpdate(EngineCommand* cmd, float fixdt);
};