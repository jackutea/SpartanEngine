#pragma once

#include "AssetManager/AssetManager.h"
#include "RenderPipeline/RenderPipeline.h"

class EngineContext {
public:
    AssetManager* assetManager;
    RenderPipeline* rp;

public:
    EngineContext() {
        assetManager = new AssetManager();
        rp = new RenderPipeline();
    }
    ~EngineContext() {
        delete assetManager;
        delete rp;
    }
};