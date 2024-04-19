#include "RenderPipelineContext.h"

class ModelAsset;

RenderPipelineContext::RenderPipelineContext() {
    sky = new SkyRenderer();
    models = new std::vector<ModelAsset *>(100);
}

RenderPipelineContext::~RenderPipelineContext() {
    delete sky;
    delete models;
}