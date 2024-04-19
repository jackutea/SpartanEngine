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
    CameraModel& cam = cmd->GetMainCamera();
    cam.Rotate({10 * dt, 1 * dt, 0});

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

// 仅设置, 没绘制
void UserMain::OnReadyDraw(EngineCommand* cmd) {
    cmd->RP_Sky_SetSolid({17, 17, 17, 255});
}

void UserMain::OnQuit() {
}