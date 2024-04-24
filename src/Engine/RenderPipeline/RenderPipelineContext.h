#ifndef ENGINE_RENDERPIPELINE_RENDERPIPELINECONTEXT_H__
#define ENGINE_RENDERPIPELINE_RENDERPIPELINECONTEXT_H__

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

#endif // ENGINE_RENDERPIPELINE_RENDERPIPELINECONTEXT_H__