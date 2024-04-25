#ifndef ENGINE_ENGINECONTEXT_H__
#define ENGINE_ENGINECONTEXT_H__

#include "RaylibExtention/VectorExtention.h"
#include "AssetManager/AssetManager.h"
#include "RenderPipeline/RenderPipeline.h"
#include "UIManager/UIManager.h"
#include "CameraManager/CameraManager.h"
#include "Core_Font/FontCore.h"

class EngineContext {
public:
    AssetManager* assetManager;
    RenderPipeline* rp;
    UIManager* ui;
    CameraManager* cameraManager;
    FontCore* fontCore;
public:
    EngineContext();
    ~EngineContext();
};

#endif // ENGINE_ENGINECONTEXT_H__