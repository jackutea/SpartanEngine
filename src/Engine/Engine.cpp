#include <iostream>
#include "Engine.h"
#include "Consts/SPT_Unicode_CN.h"

Engine::Engine() {
    ctx = new EngineContext();
}

Engine::~Engine() {
    delete ctx;
}

#pragma region LifeCycle
void Engine::Initialize() {
    // Load built-in assets
    this->Font_LoadWithUTF8("assets/built_in/fonts/SIMHEI.TTF", 30, SPT_Unicode::cn);
    // this->Font_Load("assets/built_in/fonts/SIMHEI.TTF");

    // Camera: MainCamera
    ctx->cameraManager->Initialize();

    // RP: MainLight, Sky
    ctx->rp->Initialize();
}

void Engine::LogicTick(float dt) {
    // Update Logic here
    // ctx->cameraManager->cam3D->target.x += 100 * dt;
}

void Engine::Render() {

    SetConfigFlags(FLAG_MSAA_4X_HINT);

    // [ Camera Mode Begin
    ctx->cameraManager->Begin();

    // Prepare Shader
    RenderDomain::PrepareShader(ctx);

    // Render Skybox
    CameraModel *mainCam = ctx->cameraManager->GetMainCamera();
    RenderPipeline *rp = ctx->rp;
    rp->RenderAll(*mainCam);

    // ] Camera Mode End
    ctx->cameraManager->End();
}

void Engine::ProcessAndRenderUI() {
    // Process and Render UI here
    ctx->ui->ProcessAndRender();
}
#pragma endregion

#pragma region Light
LightRenderer *Engine::Light_Create(LightType type) {
    LightRenderer *light = ctx->rp->Light_Create(type);

    for (auto &kv : *ctx->assetManager->ctx->shaders) {
        ShaderAsset *shader = kv.second;
        int index = light->index;
        shader->InitLocs(index);
    }

    return light;
}

LightRenderer *Engine::Light_GetMain() {
    return ctx->rp->GetMainLight();
}
#pragma endregion

#pragma region Sky
SkyRenderer *Engine::Sky_GetMain() {
    return ctx->rp->GetSky();
}
#pragma endregion

#pragma region Camera
CameraModel *Engine::Camera_Create() {
    CameraModel *camera = ctx->cameraManager->CreateCamera();
    return camera;
}

void Engine::Camera_SetMain(CameraModel *camera) {
    ctx->cameraManager->SetMainCamera(camera);
}

CameraModel *Engine::Camera_GetMain() {
    return ctx->cameraManager->GetMainCamera();
}

#pragma region Model
ModelAsset *Engine::Model_Load(const char *name, const char *path) {
    ModelAsset *model = ctx->assetManager->Model_Load(name, path);
    return model;
}
#pragma endregion

#pragma region Texture
TextureAsset *Engine::Texture_Load(const char *name, const char *path) {
    TextureAsset *texture = ctx->assetManager->Texture_Load(path);
    return texture;
}
#pragma endregion

#pragma region Shader
ShaderAsset *Engine::Shader_Load(const char *name, const char *vsPath, const char *fsPath) {

    ShaderAsset *shader = ctx->assetManager->Shader_Load(name, vsPath, fsPath);

    for (auto light : *ctx->rp->ctx->lights) {
        int index = light->index;
        shader->InitLocs(index);
    }

    return shader;
}

void Engine::Shader_Reload(ShaderAsset *shader) {
    UnloadShader(shader->shader);
    shader->shader = LoadShader(shader->vsPath, shader->fsPath);
    for (auto light : *ctx->rp->ctx->lights) {
        int index = light->index;
        shader->InitLocs(index);
    }
}

void Engine::Shader_ReloadAll() {
    for (auto &kv : *ctx->assetManager->ctx->shaders) {
        ShaderAsset *shader = kv.second;
        Shader_Reload(shader);
    }
}
#pragma endregion

#pragma region Font
FontAsset *Engine::Font_Load(const char *path) {

    FontAsset *font = ctx->assetManager->Font_Load(path);

    FontAsset *defaultFont = ctx->fontCore->GetDefaultFont();
    if (defaultFont == nullptr) {
        ctx->fontCore->SetDefaultFont(font);
        SLog("Set Default Font: %s", path);
    }

    return font;
}

FontAsset *Engine::Font_LoadWithUTF8(const char *path, int size, const char *unicodeText) {

    FontAsset *font = ctx->assetManager->Font_LoadWithUTF8(path, size, unicodeText);

    FontAsset *defaultFont = ctx->fontCore->GetDefaultFont();
    if (defaultFont == nullptr) {
        ctx->fontCore->SetDefaultFont(font);
        SLog("Set Default Font: %s", path);
    }

    return font;
}

void Engine::Font_SetDefault(FontAsset *font) {
    ctx->fontCore->SetDefaultFont(font);
}

FontAsset *Engine::Font_GetDefault() {
    return ctx->fontCore->GetDefaultFont();
}
#pragma endregion

#pragma region RP
void Engine::RP_Model_Add(ModelAsset *model) {
    ctx->rp->Model_Add(model);
}
#pragma endregion