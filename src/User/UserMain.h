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
    void OnStart(EngineAPI* cmd);
    void OnLogicUpdate(EngineAPI* cmd, float dt);
    void OnReadyDraw(EngineAPI* cmd);

private:
    float restFixTime;
    void OnFixLogicUpdate(EngineAPI* cmd, float fixdt);
};