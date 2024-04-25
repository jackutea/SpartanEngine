#include "AssetManager.h"

AssetManager::AssetManager() {
    ctx = new AssetManagerContext();
}

AssetManager::~AssetManager() {
    delete ctx;
}

// ==== Model ====
ModelAsset *AssetManager::Model_Load(const char *name, const char *path) {
    ModelAsset *model = new ModelAsset();
    model->tf.rotation = QuaternionIdentity();
    model->tf.translation = Vector3Zero();
    model->tf.scale = Vector3One();
    model->id = ctx->modelIDRecord++;
    model->Load(path);
    ctx->models->insert({model->id, model});
    return model;
}

ModelAsset *AssetManager::Model_GetByID(unsigned int id) {
    if (ctx->models->count(id) == 0) {
        SLog("Model not found: %d\r\n", id);
        return nullptr;
    }
    return ctx->models->at(id);
}

void AssetManager::Model_Unload(unsigned int id) {
    if (ctx->models->count(id) == 0) {
        SLog("Model not found: %d\r\n", id);
        return;
    }
    ModelAsset *model = ctx->models->at(id);
    delete model;
    ctx->models->erase(id);
}

// ==== Texture ====
TextureAsset *AssetManager::Texture_Load(const char *path) {
    TextureAsset *texture = new TextureAsset();
    texture->id = ctx->textureIDRecord++;
    texture->Load(path);
    ctx->textures->insert({texture->id, texture});
    return texture;
}

TextureAsset *AssetManager::Texture_LoadCubemap(const char *name, const char *path) {
    TextureAsset *texture = new TextureAsset();
    texture->id = ctx->textureIDRecord++;
    texture->LoadCubemapVertical(name, path);
    ctx->textures->insert({texture->id, texture});
    return texture;
}

TextureAsset *AssetManager::Texture_GetByID(unsigned int id) {
    if (ctx->textures->count(id) == 0) {
        SLog("Texture not found: %d", id);
        return nullptr;
    }
    return ctx->textures->at(id);
}

void AssetManager::Texture_Unload(unsigned int id) {
    if (ctx->textures->count(id) == 0) {
        SLog("Texture not found: %d", id);
        return;
    }
    TextureAsset *texture = ctx->textures->at(id);
    delete texture;
    ctx->textures->erase(id);
}

// ==== Shader ====
ShaderAsset *AssetManager::Shader_Load(const char *name, const char *vsPath, const char *fsPath) {
    ShaderAsset *shader = new ShaderAsset();
    shader->Load(name, vsPath, fsPath);
    ctx->shaders->insert({shader->shader.id, shader});
    ctx->shadersByString->insert({name, shader});
    return shader;
}

ShaderAsset *AssetManager::Shader_GetByID(unsigned int id) {
    if (ctx->shaders->count(id) == 0) {
        SLog("Shader not found: %d\r\n", id);
        return nullptr;
    }
    return ctx->shaders->at(id);
}

ShaderAsset *AssetManager::Shader_GetByName(const char *name) {
    if (ctx->shadersByString->count(name) == 0) {
        SLog("Shader not found: %s\r\n", name);
        return nullptr;
    }
    return ctx->shadersByString->at(name);
}

void AssetManager::Shader_Unload(unsigned int id) {
    if (ctx->shaders->count(id) == 0) {
        SLog("Shader not found: %d\r\n", id);
        return;
    }
    ShaderAsset *shader = ctx->shaders->at(id);
    ctx->shaders->erase(id);
    ctx->shadersByString->erase(shader->name);
    delete shader;
}

void AssetManager::Shader_Unload(const char *name) {
    if (ctx->shadersByString->count(name) == 0) {
        SLog("Shader not found: %s\r\n", name);
        return;
    }
    ShaderAsset *shader = ctx->shadersByString->at(name);
    ctx->shadersByString->erase(name);
    ctx->shaders->erase(shader->GetID());
    delete shader;
}

// ==== Font ====
FontAsset *AssetManager::Font_Load(const char *path) {
    FontAsset *font = new FontAsset();
    font->id = ctx->fontIDRecord++;
    font->Load(path);
    ctx->fonts->insert({font->id, font});
    return font;
}

FontAsset *AssetManager::Font_LoadWithUTF8(const char *path, int size, const char *unicodeText) {
    FontAsset *font = new FontAsset();
    font->id = ctx->fontIDRecord++;
    font->LoadWithUTF8(path, size, unicodeText);
    ctx->fonts->insert({font->id, font});
    return font;
}

FontAsset *AssetManager::Font_GetByID(int id) {
    if (ctx->fonts->count(id) == 0) {
        SLog("Font not found: %d\r\n", id);
        return nullptr;
    }
    return ctx->fonts->at(id);
}