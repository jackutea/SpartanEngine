#include "Engine.h"
#include <iostream>

Engine::Engine() {
    ctx = new EngineContext();
}

Engine::~Engine() {
    delete ctx;
}

#pragma region LifeCycle
void Engine::Initialize() {
    // Load built-in assets

    // Camera
    ctx->cameraManager->Initialize();

    // RP
    ctx->rp->Initialize();
}

void Engine::LogicTick(float dt) {
    // Update Logic here
    // ctx->cameraManager->cam3D->target.x += 100 * dt;
}

void Engine::Render() {

    // [ Camera Mode Begin
    ctx->cameraManager->Begin();

    // Prepare Shader
    RenderDomain::PrepareShader(ctx);

    // Render Skybox
    CameraModel *mainCam = ctx->cameraManager->GetMainCamera();
    RenderPipeline *rp = ctx->rp;
    rp->RenderAll(*mainCam);

    // ] Camera Mode End
    ctx->cameraManager->End();
}

void Engine::ProcessAndRenderUI() {
    // Process and Render UI here
    ctx->ui->ProcessAndRender();
}
#pragma endregion

#pragma region Light
LightRenderer *Engine::Light_Create(LightType type) {
    LightRenderer *light = ctx->rp->Light_Create(type);

    for (auto &kv : *ctx->assetManager->ctx->shaders) {
        ShaderAsset *shader = kv.second;
        int index = light->index;
        shader->InitLocs(index);
    }

    return light;
}
#pragma endregion

#pragma region Model
ModelAsset *Engine::Model_Load(const char *name, const char *path) {
    ModelAsset *model = ctx->assetManager->LoadModel(name, path);
    return model;
}
#pragma endregion

#pragma region Texture
TextureAsset *Engine::Texture_Load(const char *name, const char *path) {
    TextureAsset *texture = ctx->assetManager->LoadTexture(path);
    return texture;
}
#pragma endregion

#pragma region Shader
ShaderAsset *Engine::Shader_Load(const char *name, const char *vsPath, const char *fsPath) {

    ShaderAsset *shader = ctx->assetManager->LoadShader(name, vsPath, fsPath);

    for (auto light : *ctx->rp->ctx->lights) {
        int index = light->index;
        shader->InitLocs(index);
    }

    return shader;
}
#pragma endregion