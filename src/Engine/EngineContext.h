#pragma once

#include "AssetManager/AssetManager.h"
#include "RenderPipeline/RenderPipeline.h"
#include "UIManager/UIManager.h"
#include "CameraManager/CameraManager.h"

class EngineContext {
public:
    AssetManager* assetManager;
    RenderPipeline* rp;
    UIManager* ui;
    CameraManager* cameraManager;

public:
    EngineContext() {
        assetManager = new AssetManager();
        rp = new RenderPipeline();
        ui = new UIManager();
        cameraManager = new CameraManager();
    }
    ~EngineContext() {
        delete assetManager;
        delete rp;
        delete ui;
        delete cameraManager;
    }
};