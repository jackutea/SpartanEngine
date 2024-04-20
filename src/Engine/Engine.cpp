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