#include "EngineContext.h"

EngineContext::EngineContext() {
    assetManager = new AssetManager();
    rp = new RenderPipeline();
    ui = new UIManager();
    cameraManager = new CameraManager();
}

EngineContext::~EngineContext() {
    delete assetManager;
    delete rp;
    delete ui;
    delete cameraManager;
}