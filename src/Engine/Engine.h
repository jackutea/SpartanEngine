#pragma once

#include "EngineContext.h"
#include "Domain/export.h"

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

#pragma region Model
    ModelAsset* Model_Load(const char* name, const char* path);
#pragma endregion

#pragma region Texture
    TextureAsset* Texture_Load(const char* name, const char* path);
#pragma endregion

#pragma region Shader
    ShaderAsset* Shader_Load(const char* name, const char* vsPath, const char* fsPath);
#pragma endregion

#pragma region Font
    FontAsset* Font_Load(const char* path);
    FontAsset* Font_LoadWithUTF8(const char* path, int size, const char* unicodeText);
    void Font_SetDefault(FontAsset* font);
#pragma endregion
};
