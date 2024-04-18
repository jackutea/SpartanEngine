#pragma once

#include "UIManagerContext.h"

class UIManager {
public:
    UIManagerContext* ctx;

public:
    UIManager();
    ~UIManager();
    void ProcessAndRender();
};
