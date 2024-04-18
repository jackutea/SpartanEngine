#include "UserMain.h"

UserMain::UserMain() {
    ctx = new UserContext();
    restFixTime = 0;
}

UserMain::~UserMain() {
    delete ctx;
}

void UserMain::OnStart(EngineCommand* cmd) {
}

void UserMain::OnLogicUpdate(EngineCommand* cmd, float dt) {

    // 1. Process Input

    // 2. Logic Tick
    float fixInterval = PublishSetting::FIXED_TIME_STEP;
    restFixTime += dt;
    if (restFixTime < fixInterval) {
        OnFixLogicUpdate(cmd, restFixTime);
        restFixTime = 0;
    } else {
        while (restFixTime >= fixInterval) {
            OnFixLogicUpdate(cmd, fixInterval);
            restFixTime -= fixInterval;
        }
    }
}

void UserMain::OnFixLogicUpdate(EngineCommand* cmd, float fixdt) {
}

void UserMain::OnReadyDraw(EngineCommand* cmd) {
    cmd->RP_Sky_SetSolid(RAYWHITE);
}

void UserMain::OnQuit() {
}