#include "EngineContext.h"

EngineContext::EngineContext() {
    assetManager = new AssetManager();
    rp = new RenderPipeline();
    ui = new UIManager();
    cameraManager = new CameraManager();
    fontCore = new FontCore();
}

EngineContext::~EngineContext() {
    delete assetManager;
    delete rp;
    delete ui;
    delete cameraManager;
    delete fontCore;
}