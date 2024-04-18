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
    // Load built-in assets here

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
    DrawCubeWiresV((Vector3){0, 0, 0}, (Vector3){20, 20, 20}, RED);

    // ] Camera Mode End
    ctx->cameraManager->End();
}

void Engine::ProcessAndRenderUI() {
    // Process and Render UI here
    ctx->ui->ProcessAndRender();
}