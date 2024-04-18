#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "import.h"
#include "Models/export.h"

using namespace std;

class AssetManagerContext {
public:
    int modelIDRecord;
    unordered_map<int, ModelAsset *> *models;

    int textureIDRecord;
    unordered_map<int, TextureAsset *> *textures;

    int shaderIDRecord;
    unordered_map<int, ShaderAsset *> *shaders;

public:
    AssetManagerContext();
    ~AssetManagerContext();
};