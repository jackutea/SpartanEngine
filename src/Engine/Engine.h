#pragma once

#include "EngineContext.h"
#include "EngineCommand.h"

class Engine {
public:
    EngineContext* ctx;
    EngineCommand* cmd;

public:
    Engine();
    ~Engine();
    void Initialize();
    void LogicTick(float dt);
    void Render();
    void ProcessAndRenderUI();
};
