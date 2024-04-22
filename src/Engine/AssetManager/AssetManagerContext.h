#pragma once
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

    int fontIDRecord;
    unordered_map<int, FontAsset *> *fonts;

public:
    AssetManagerContext();
    ~AssetManagerContext();
};