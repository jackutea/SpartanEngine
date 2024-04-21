#include "RenderPipelineContext.h"

class ModelAsset;

RenderPipelineContext::RenderPipelineContext() {
    sky = new SkyRenderer();
    lights = new std::vector<LightRenderer *>();
    models = new std::vector<ModelAsset *>();
}

RenderPipelineContext::~RenderPipelineContext() {
    delete sky;

    for (auto light : *lights) {
        delete light;
    }
    delete lights;

    // Just Model Queue, Model Asset will be deleted by AssetManager
    delete models;
}

LightRenderer *RenderPipelineContext::GetMainLight() {
    return lights->at(mainLightID);
}