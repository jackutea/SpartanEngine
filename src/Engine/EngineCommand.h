#pragma once

#include "EngineContext.h"

class EngineCommand {
private:
    EngineContext* ctx;

public:
    EngineCommand(EngineContext* ctx);
    ~EngineCommand();

    // ==== Asset ====
    AssetManager* GetAssetManager();

    // ==== Camera ====
    CameraModel* GetMainCamera();

    // ==== RP ====
    LightRenderer* RP_GetMainLight();
    void RP_Sky_SetSolid(Color color);
    void RP_Model_Add(ModelAsset* model);

};