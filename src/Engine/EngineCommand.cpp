#include "EngineContext.h"
#include "EngineCommand.h"
#include "RenderPipeline/RenderPipeline.h"

EngineCommand::EngineCommand() {
}

EngineCommand::~EngineCommand() {
    delete engine;
}

void EngineCommand::Inject(Engine* engine) {
    this->engine = engine;
}

// ==== Asset ====
AssetManager* EngineCommand::GetAssetManager() {
    return engine->ctx->assetManager;
}

ShaderAsset* EngineCommand::LoadShader(const char* name, const char* vsPath, const char* fsPath) {
    return engine->Shader_Load(name, vsPath, fsPath);
}

// ==== Camera ====
CameraModel* EngineCommand::GetMainCamera() {
    return engine->ctx->cameraManager->GetMainCamera();
}

// ==== RP ====
LightRenderer* EngineCommand::RP_GetMainLight() {
    return engine->ctx->rp->GetMainLight();
}

void EngineCommand::RP_Sky_SetSolid(Color color) {
    engine->ctx->rp->Sky_SetSolidColor(color);
}

void EngineCommand::RP_Model_Add(ModelAsset* model) {
    engine->ctx->rp->Model_Add(model);
}