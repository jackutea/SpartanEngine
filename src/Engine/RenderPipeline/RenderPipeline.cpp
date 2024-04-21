#include "RenderPipeline.h"

RenderPipeline::RenderPipeline() {
    ctx = new RenderPipelineContext();
}

RenderPipeline::~RenderPipeline() {
    delete ctx;
}

void RenderPipeline::Initialize() {

    // Light
    LightRenderer* light = Light_Create(LightType::Directional);
    ctx->mainLightID = light->index;

    // Sky
    Sky_SetSolidColor(RAYWHITE);
}

void RenderPipeline::RenderAll(CameraModel& cam) {
    // Light
    // View
    Sky_Render(cam);
    Model_Render(cam);
}

// ==== Light ====
LightRenderer* RenderPipeline::Light_Create(LightType type) {
    LightRenderer* light = new LightRenderer();
    light->index = ctx->lights->size();
    light->type = type;
    light->isEnable = true;
    light->pos = {0, 0, 0};
    light->target = {0.2f, 0.3f, 0};
    light->color = WHITE;
    light->attenuation = 0.2f;
    ctx->lights->push_back(light);
    return light;
}

LightRenderer* RenderPipeline::GetMainLight() {
    return ctx->lights->at(ctx->mainLightID);
}

// ==== Sky ====
void RenderPipeline::Sky_Render(CameraModel& cam) const {
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

void RenderPipeline::Model_Render(CameraModel& cam) {
    for (int i = 0; i < ctx->models->size(); ++i) {
        ModelAsset* model = ctx->models->at(i);
        model->Draw();
    }
    ctx->models->clear();
}