#pragma once

#include <vector>
#include "../AssetManager/AssetManager.h"
#include "import.h"

class RenderPipelineContext {
public:
    SkyRenderer *sky;

    int mainLightID;
    int lightIDRecord;
    std::unordered_map<int, LightRenderer *> *lights;
    std::vector<ModelAsset *> *models;

    AssetManagerContext *assetManagerCtx;

public:
    RenderPipelineContext();
    ~RenderPipelineContext();

    void Inject(AssetManagerContext *assetManagerCtx);

    LightRenderer* GetMainLight();
};