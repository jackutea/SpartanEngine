#include "EngineContext.h"
#include "EngineAPI.h"
#include "RenderPipeline/RenderPipeline.h"

EngineAPI::EngineAPI() {
}

EngineAPI::~EngineAPI() {
    delete engine;
}

void EngineAPI::Inject(Engine* engine) {
    this->engine = engine;
}

// ==== Asset ====
ModelAsset* EngineAPI::Asset_LoadModel(const char* name, const char* path) {
    return engine->Model_Load(name, path);
}

TextureAsset* EngineAPI::Asset_LoadTexture(const char* name, const char* path) {
    return engine->Texture_Load(name, path);
}

ShaderAsset* EngineAPI::Asset_LoadShader(const char* name, const char* vsPath, const char* fsPath) {
    return engine->Shader_Load(name, vsPath, fsPath);
}

void EngineAPI::Asset_ReloadShader(ShaderAsset* shader) {
    engine->Shader_Reload(shader);
}

void EngineAPI::Asset_ReloadAllShader() {
    engine->Shader_ReloadAll();
}

FontAsset* EngineAPI::Asset_LoadFont(const char* path) {
    return engine->Font_Load(path);
}

// ==== Font ====
void EngineAPI::Font_SetDefault(FontAsset* font) {
    engine->Font_SetDefault(font);
}

FontAsset* EngineAPI::Font_GetDefault() {
    return engine->Font_GetDefault();
}

// ==== Camera ====
CameraModel* EngineAPI::Camera_GetMain() {
    return engine->Camera_GetMain();
}

// ==== RP ====
LightRenderer* EngineAPI::RP_GetMainLight() {
    return engine->Light_GetMain();
}

SkyRenderer* EngineAPI::RP_GetSky() {
    return engine->Sky_GetMain();
}

void EngineAPI::RP_Model_Add(ModelAsset* model) {
    engine->RP_Model_Add(model);
}