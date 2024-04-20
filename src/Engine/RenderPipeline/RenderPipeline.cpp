#include "RenderPipeline.h"

RenderPipeline::RenderPipeline() {
    ctx = new RenderPipelineContext();
}

RenderPipeline::~RenderPipeline() {
    delete ctx;
}

// ==== Sky ====
void RenderPipeline::Sky_Render() const {
    SkyRenderer* sky = ctx->sky;
    if (sky->skyType == RPSkyType::SolidColor) {
        // Render solid sky
        ClearBackground(sky->solidColor);
    }
}

void RenderPipeline::Sky_SetSolidColor(Color color) {
    SkyRenderer* sky = ctx->sky;
    sky->skyType = RPSkyType::SolidColor;
    sky->solidColor = color;
}

// ==== Model ====
void RenderPipeline::Model_Add(ModelAsset* model) {
    ctx->models->push_back(model);
}

void RenderPipeline::Model_Render() {
    for (int i = ctx->models->size() - 1; i >= 0; i--) {
        ModelAsset* model = ctx->models->at(i);
        model->Draw();
        // ctx->models->pop_back();
    }
    ctx->models->clear();
}