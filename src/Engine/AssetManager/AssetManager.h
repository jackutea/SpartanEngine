#pragma once

#include "import.h"
#include "AssetManagerContext.h"

class AssetManager {
public:
    AssetManagerContext *ctx;

public:
    AssetManager();
    ~AssetManager();
    
    ModelAsset *LoadModel(const char *path);
    ModelAsset *GetModel(unsigned int id);
    void UnloadModel(unsigned int id);

    TextureAsset *LoadTexture(const char *path);
    TextureAsset *GetTexture(unsigned int id);
    void UnloadTexture(unsigned int id);

    ShaderAsset *LoadShader(const char *vsPath, const char *fsPath);
    ShaderAsset *GetShader(unsigned int id);
    void UnloadShader(unsigned int id);
};