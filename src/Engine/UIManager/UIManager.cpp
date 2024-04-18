#include "UIManager.h"

UIManager::UIManager() {
    ctx = new UIManagerContext();
}

UIManager::~UIManager() {
    delete ctx;
}

void UIManager::ProcessAndRender() {
    // Process and Render UI here
}
