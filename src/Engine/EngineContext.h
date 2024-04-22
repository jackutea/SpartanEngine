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
    EngineContext();
    ~EngineContext();
};