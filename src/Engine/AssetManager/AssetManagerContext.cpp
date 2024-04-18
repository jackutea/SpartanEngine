#include "AssetManagerContext.h"

AssetManagerContext::AssetManagerContext() {
    modelIDRecord = 0;
    models = new unordered_map<int, ModelAsset *>();

    textureIDRecord = 0;
    textures = new unordered_map<int, TextureAsset *>();

    shaderIDRecord = 0;
    shaders = new unordered_map<int, ShaderAsset *>();
}

AssetManagerContext::~AssetManagerContext() {
    // - Release all models
    for (auto &model : *models) {
        delete model.second;
    }
    models->clear();
    delete models;

    // - Release all textures
    for (auto &texture : *textures) {
        delete texture.second;
    }
    textures->clear();
    delete textures;

    // - Release all shaders
    for (auto &shader : *shaders) {
        delete shader.second;
    }
    shaders->clear();
    delete shaders;
}