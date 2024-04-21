#pragma once

#include <vector>
#include "../AssetManager/AssetManager.h"
#include "import.h"

class RenderPipelineContext {
public:
    SkyRenderer *sky;

    int mainLightID;
    int lightIDRecord;
    std::vector<LightRenderer *> *lights;
    std::vector<ModelAsset *> *models;

public:
    RenderPipelineContext();
    ~RenderPipelineContext();

    LightRenderer* GetMainLight();
};