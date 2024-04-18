#include "Engine.h"

Engine::Engine() {
    ctx = new EngineContext();
    cmd = new EngineCommand(ctx);
}

Engine::~Engine() {
    delete cmd;
    delete ctx;
}

void Engine::LoadBuiltInAssets() {
    // Load built-in assets here
}

void Engine::Render() {
    // Render code here

    // Render Skybox
    ctx->rp->Sky_Render();

}