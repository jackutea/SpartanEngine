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
    RenderPipeline *rp = ctx->rp;
    rp->Sky_Render();

    // Render Models
    rp->Model_Render();

    // ] Camera Mode End
    ctx->cameraManager->End();
}

void Engine::ProcessAndRenderUI() {
    // Process and Render UI here
    ctx->ui->ProcessAndRender();
}