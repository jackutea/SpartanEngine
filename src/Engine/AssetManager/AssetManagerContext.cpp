#include "AssetManagerContext.h"

AssetManagerContext::AssetManagerContext() {
    modelIDRecord = 0;
    models = new unordered_map<unsigned int, ModelAsset *>(100);

    textureIDRecord = 0;
    textures = new unordered_map<unsigned int, TextureAsset *>(100);

    shaderIDRecord = 0;
    shaders = new unordered_map<unsigned int, ShaderAsset *>(100);

    fontIDRecord = 0;
    fonts = new unordered_map<int, FontAsset *>(100);
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

    // - Release all fonts
    for (auto &font : *fonts) {
        delete font.second;
    }
    fonts->clear();
    delete fonts;
}