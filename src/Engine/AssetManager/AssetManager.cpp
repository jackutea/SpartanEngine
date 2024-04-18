#include "AssetManager.h"

AssetManager::AssetManager() {
    ctx = new AssetManagerContext();
}

AssetManager::~AssetManager() {
    delete ctx;
}

// ==== Model ====
ModelAsset *AssetManager::LoadModel(const char *path) {
    ModelAsset *model = new ModelAsset();
    model->id = ctx->modelIDRecord++;
    model->Load(path);
    ctx->models->insert({model->id, model});
    return model;
}

ModelAsset *AssetManager::GetModel(int id) {
    return ctx->models->at(id);
}

// ==== Texture ====
TextureAsset *AssetManager::LoadTexture(const char *path) {
    TextureAsset *texture = new TextureAsset();
    texture->id = ctx->textureIDRecord++;
    texture->Load(path);
    ctx->textures->insert({texture->id, texture});
    return texture;
}

TextureAsset *AssetManager::GetTexture(int id) {
    return ctx->textures->at(id);
}

// ==== Shader ====
ShaderAsset *AssetManager::LoadShader(const char *vsPath, const char *fsPath) {
    ShaderAsset *shader = new ShaderAsset();
    shader->id = ctx->shaderIDRecord++;
    shader->Load(vsPath, fsPath);
    ctx->shaders->insert({shader->id, shader});
    return shader;
}

ShaderAsset *AssetManager::GetShader(int id) {
    return ctx->shaders->at(id);
}