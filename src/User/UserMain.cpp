#include "UserMain.h"

UserMain::UserMain() {
    ctx = new UserContext();
    restTime = 0;
}

UserMain::~UserMain() {
    delete ctx;
}

void UserMain::OnStart() {
}

void UserMain::OnLogicUpdate(float dt) {
    restTime += dt;

    // 1. Process Input

    // 2. Logic Tick
    const float fixInterval = 0.01f;
    if (restTime < fixInterval) {
        OnFixLogicUpdate(restTime);
        restTime = 0;
    } else {
        while (restTime >= fixInterval) {
            OnFixLogicUpdate(fixInterval);
            restTime -= fixInterval;
        }
    }
}

void UserMain::OnFixLogicUpdate(float fixdt) {
}

void UserMain::OnReadyDraw() {
}

void UserMain::OnQuit() {
}