#include "Engine.h"
#include <iostream>

Engine::Engine() {
    ctx = new EngineContext();
    cmd = new EngineCommand(ctx);
}

Engine::~Engine() {
    delete cmd;
    delete ctx;
}

void Engine::Initialize() {
    // Load built-in assets
    ctx->assetManager->LoadModel("assets/built_in/models/mesh_sphere.glb");
    // ctx->assetManager->LoadModel("assets/built_in/models/model_cube.fbx");
    // ctx->assetManager->LoadTexture("assets/built_in/textures/tex_white.png");
    ctx->assetManager->LoadTexture("assets/built_in/models/watermill_diffuse.png");
    ctx->assetManager->LoadShader(0, "assets/built_in/shaders/glsl330/grayscale.fs");

    // Camera
    ctx->cameraManager->Initialize();
}

void Engine::LogicTick(float dt) {
    // Update Logic here
    // ctx->cameraManager->cam3D->target.x += 100 * dt;
}

void Engine::Render() {

    // [ Camera Mode Begin
    ctx->cameraManager->Begin();

    // Render Skybox
    ctx->rp->Sky_Render();

    // Render Models
    // DrawCubeWiresV((Vector3){0, 0, 0}, (Vector3){20, 20, 20}, RED);
    TextureAsset *tex = ctx->assetManager->GetTexture(0);
    ModelAsset *model= ctx->assetManager->GetModel(0);
    ShaderAsset *shader = ctx->assetManager->GetShader(0);
    model->SetTexture(0, 0, tex->texture);
    model->SetShader(0, shader->shader);
    model->Draw((Vector3){0, 0, 0}, (Vector3){0, 1, 0}, 45, (Vector3){5, 5, 5});

    // ] Camera Mode End
    ctx->cameraManager->End();
}

void Engine::ProcessAndRenderUI() {
    // Process and Render UI here
    ctx->ui->ProcessAndRender();
}