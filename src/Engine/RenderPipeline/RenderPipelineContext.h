#pragma once

#include <vector>
#include "../AssetManager/AssetManager.h"
#include "import.h"

class RenderPipelineContext {
public:
    SkyRenderer *sky;
    std::vector<ModelAsset *> *models;

public:
    RenderPipelineContext();
    ~RenderPipelineContext();
};