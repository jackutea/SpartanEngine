#include "RenderPipeline.h"

RenderPipeline::RenderPipeline() {
    ctx = new RenderPipelineContext();
}

void RenderPipeline::Sky_Render() {
    auto sky = ctx->sky;
    if (sky.skyType == RPSkyType::SolidColor) {
        // Render solid sky
        ClearBackground(sky.solidColor);
    }
}

void RenderPipeline::Sky_SetSolidColor(Color color) {
    RPSkyModel& sky = ctx->sky;
    sky.skyType = RPSkyType::SolidColor;
    sky.solidColor = color;
}