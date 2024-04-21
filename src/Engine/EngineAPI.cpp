#include "EngineContext.h"
#include "EngineAPI.h"
#include "RenderPipeline/RenderPipeline.h"

EngineAPI::EngineAPI() {
}

EngineAPI::~EngineAPI() {
    delete engine;
}

void EngineAPI::Inject(Engine* engine) {
    this->engine = engine;
}

// ==== Asset ====
AssetManager* EngineAPI::GetAssetManager() {
    return engine->ctx->assetManager;
}

ShaderAsset* EngineAPI::LoadShader(const char* name, const char* vsPath, const char* fsPath) {
    return engine->Shader_Load(name, vsPath, fsPath);
}

// ==== Camera ====
CameraModel* EngineAPI::GetMainCamera() {
    return engine->ctx->cameraManager->GetMainCamera();
}

// ==== RP ====
LightRenderer* EngineAPI::RP_GetMainLight() {
    return engine->ctx->rp->GetMainLight();
}

void EngineAPI::RP_Sky_SetSolid(Color color) {
    engine->ctx->rp->Sky_SetSolidColor(color);
}

void EngineAPI::RP_Model_Add(ModelAsset* model) {
    engine->ctx->rp->Model_Add(model);
}