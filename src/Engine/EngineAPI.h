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
    AssetManager* GetAssetManager();
    ShaderAsset* Asset_LoadShader(const char* name, const char* vsPath, const char* fsPath);

    // ==== Camera ====
    CameraModel* GetMainCamera();

    // ==== RP ====
    LightRenderer* RP_GetMainLight();
    void RP_Sky_SetSolid(Color color);
    void RP_Model_Add(ModelAsset* model);
};