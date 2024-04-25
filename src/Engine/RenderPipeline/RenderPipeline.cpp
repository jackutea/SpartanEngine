#include "RenderPipeline.h"

#define RLGL_IMPLEMENTATION

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
    Sky_SetAsSolidColor(RAYWHITE);
}

void RenderPipeline::RenderAll(CameraModel& cam) {
    SkyRenderer* sky = ctx->sky;
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
    light->pos = {-2, 1, -2};
    light->target = {0, 0, 0};
    light->color = {255, 255, 255, 255};
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
    } else if (sky->skyType == RPSkyType::Cubemap) {
        // Render cubemap sky
        ClearBackground(sky->solidColor);
        rlDisableBackfaceCulling();
        rlDisableDepthMask();
        sky->skyboxModel->Draw();
        rlEnableBackfaceCulling();
        rlEnableDepthMask();
    }
}

SkyRenderer* RenderPipeline::GetSky() {
    return ctx->sky;
}

void RenderPipeline::Sky_SetAsSolidColor(Color color) {
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