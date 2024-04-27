#pragma once

#include "import.h"
#include "UserContext.h"
#include "UserSetting.h"

class UserMain {
public:
    UserContext* ctx;

public:
    UserMain();
    ~UserMain();
    void Initialize(EngineAPI* api);
    void OnLogicUpdate(EngineAPI* api, float dt);
    void OnReadyDraw(EngineAPI* api);
    void OnPostGUI(EngineAPI* api, float dt);

private:
    float restFixTime;
    void OnFixLogicUpdate(EngineAPI* api, float fixdt);
};