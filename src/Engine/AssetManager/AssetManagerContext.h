#ifndef ENGINE_ASSETMANAGER_ASSETMANAGERCONTEXT_H__
#define ENGINE_ASSETMANAGER_ASSETMANAGERCONTEXT_H__

#include <iostream>
#include <vector>
#include <unordered_map>
#include "import.h"
#include "../Models/export.h"

using namespace std;

class AssetManagerContext {
public:
    
    unsigned int modelIDRecord;
    unordered_map<unsigned int, ModelAsset *> *models;
    
    unsigned int textureIDRecord;
    unordered_map<unsigned int, TextureAsset *> *textures;

    unsigned int shaderIDRecord;
    unordered_map<unsigned int, ShaderAsset *> *shaders;
    unordered_map<const char *, ShaderAsset *> *shadersByString;

    int fontIDRecord;
    unordered_map<int, FontAsset *> *fonts;

public:
    AssetManagerContext();
    ~AssetManagerContext();
};

#endif // ENGINE_ASSETMANAGER_ASSETMANAGERCONTEXT_H__