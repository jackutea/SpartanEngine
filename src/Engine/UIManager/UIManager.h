#pragma once

#include "UIManagerContext.h"

class UIManager {
private:
    UIManagerContext* ctx;

public:
    UIManager();
    ~UIManager();
    void ProcessAndRender();
};
