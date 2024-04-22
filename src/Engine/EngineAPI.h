#pragma once

#include "Engine.h"

class EngineAPI {
private:
    Engine* engine;

public:
    EngineAPI();
    ~EngineAPI();

    void Inject(Engine* engine);

    // ==== Asset ====
    ModelAsset* Asset_LoadModel(const char* name, const char* path);
    TextureAsset* Asset_LoadTexture(const char* name, const char* path);
    ShaderAsset* Asset_LoadShader(const char* name, const char* vsPath, const char* fsPath);

    // ==== Camera ====
    CameraModel* Camera_GetMain();

    // ==== RP ====
    LightRenderer* RP_GetMainLight();
    SkyRenderer* RP_GetSky();
    void RP_Model_Add(ModelAsset* model);
};