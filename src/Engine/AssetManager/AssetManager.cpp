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
    model->tf.rotation = QuaternionIdentity();
    model->tf.translation = Vector3Zero();
    model->tf.scale = Vector3One();
    model->id = ctx->modelIDRecord++;
    model->Load(path);
    ctx->models->insert({model->id, model});
    return model;
}

ModelAsset *AssetManager::GetModel(unsigned int id) {
    if (ctx->models->count(id) == 0) {
        SLog("Model not found: %d\r\n", id);
        return nullptr;
    }
    return ctx->models->at(id);
}

void AssetManager::UnloadModel(unsigned int id) {
    if (ctx->models->count(id) == 0) {
        SLog("Model not found: %d\r\n", id);
        return;
    }
    ModelAsset *model = ctx->models->at(id);
    delete model;
    ctx->models->erase(id);
}

// ==== Texture ====
TextureAsset *AssetManager::LoadTexture(const char *path) {
    TextureAsset *texture = new TextureAsset();
    texture->id = ctx->textureIDRecord++;
    texture->Load(path);
    ctx->textures->insert({texture->id, texture});
    return texture;
}

TextureAsset *AssetManager::GetTexture(unsigned int id) {
    if (ctx->textures->count(id) == 0) {
        SLog("Texture not found: %d", id);
        return nullptr;
    }
    return ctx->textures->at(id);
}

void AssetManager::UnloadTexture(unsigned int id) {
    if (ctx->textures->count(id) == 0) {
        SLog("Texture not found: %d", id);
        return;
    }
    TextureAsset *texture = ctx->textures->at(id);
    delete texture;
    ctx->textures->erase(id);
}

// ==== Shader ====
ShaderAsset *AssetManager::LoadShader(const char *name, const char *vsPath, const char *fsPath) {
    ShaderAsset *shader = new ShaderAsset();
    shader->Load(name, vsPath, fsPath);
    ctx->shaders->insert({shader->shader.id, shader});
    return shader;
}

ShaderAsset *AssetManager::GetShader(unsigned int id) {
    if (ctx->shaders->count(id) == 0) {
        SLog("Shader not found: %d\r\n", id);
        return nullptr;
    }
    return ctx->shaders->at(id);
}

void AssetManager::UnloadShader(unsigned int id) {
    if (ctx->shaders->count(id) == 0) {
        SLog("Shader not found: %d\r\n", id);
        return;
    }
    ShaderAsset *shader = ctx->shaders->at(id);
    delete shader;
    ctx->shaders->erase(id);
}