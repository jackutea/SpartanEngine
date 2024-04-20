#include "EngineContext.h"
#include "EngineCommand.h"
#include "RenderPipeline/RenderPipeline.h"

EngineCommand::EngineCommand(EngineContext* ctx) {
    this->ctx = ctx;
}

EngineCommand::~EngineCommand() {
    delete ctx;
}

// ==== Asset ====
AssetManager* EngineCommand::GetAssetManager() {
    return ctx->assetManager;
}

// ==== Camera ====
CameraModel* EngineCommand::GetMainCamera() {
    return ctx->cameraManager->GetMainCamera();
}

// ==== RP ====
LightRenderer* EngineCommand::RP_GetMainLight() {
    return ctx->rp->GetMainLight();
}

void EngineCommand::RP_Sky_SetSolid(Color color) {
    ctx->rp->Sky_SetSolidColor(color);
}

void EngineCommand::RP_Model_Add(ModelAsset* model) {
    ctx->rp->Model_Add(model);
}