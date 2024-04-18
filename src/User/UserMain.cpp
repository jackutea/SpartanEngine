#include "UserMain.h"

UserMain::UserMain() {
    this->restTime = 0;
}

void UserMain::OnStart() {
}

void UserMain::OnLogicUpdate(float dt) {
    this->restTime += dt;

    const float fixInterval = 0.01f;
    if (this->restTime < fixInterval) {
        this->OnFixLogicUpdate(this->restTime);
        this->restTime = 0;
    } else {
        while (this->restTime >= fixInterval) {
            this->OnFixLogicUpdate(fixInterval);
            this->restTime -= fixInterval;
        }
    }
}

void UserMain::OnFixLogicUpdate(float fixdt) {
}

void UserMain::OnQuit() {
}