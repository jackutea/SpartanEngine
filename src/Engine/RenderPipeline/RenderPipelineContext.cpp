#include "RenderPipelineContext.h"

class ModelAsset;

RenderPipelineContext::RenderPipelineContext() {
    sky = new SkyRenderer();
    lights = new std::unordered_map<int, LightRenderer *>();
    models = new std::vector<ModelAsset *>();
}

RenderPipelineContext::~RenderPipelineContext() {
    delete sky;

    for (auto &light : *lights) {
        delete light.second;
    }
    delete lights;

    // Just Model Queue, Model Asset will be deleted by AssetManager
    delete models;
}

void RenderPipelineContext::Inject(AssetManagerContext *assetManagerCtx) {
    this->assetManagerCtx = assetManagerCtx;
}

LightRenderer *RenderPipelineContext::GetMainLight() {
    return lights->at(mainLightID);
}