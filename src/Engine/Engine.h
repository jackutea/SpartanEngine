#pragma once

#include "EngineContext.h"

class Engine {
public:
    EngineContext* ctx;

public:
    Engine();
    ~Engine();

#pragma region LifeCycle
    void Initialize();
    void LogicTick(float dt);
    void Render();
    void ProcessAndRenderUI();
#pragma endregion

#pragma region Light
    LightRenderer* Light_Create(LightType type);
#pragma endregion

#pragma region Shader
    ShaderAsset* Shader_Load(const char* name, const char* vsPath, const char* fsPath);
#pragma endregion
};
