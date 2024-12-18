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

void EngineAPI::Test_ForScripts() {
    SLog("Test for scripts");
}

// ==== Asset ====
ModelAsset* EngineAPI::Asset_LoadModel(const char* name, const char* path) {
    return engine->Model_Load(name, path);
}

ModelAsset* EngineAPI::Asset_GetModel(unsigned int id) {
    return engine->Model_Get(id);
}

TextureAsset* EngineAPI::Asset_LoadTexture(const char* name, const char* path) {
    return engine->Texture_Load(name, path);
}

TextureAsset* EngineAPI::Asset_GetTexture(unsigned int id) {
    return engine->Texture_Get(id);
}

TextureAsset* EngineAPI::Asset_LoadCubemapTexture(const char* name, const char* path) {
    return engine->Texture_LoadCubemap(name, path);
}

TextureAsset* EngineAPI::Asset_LoadCubemapHDRI(Shader shader, int size, int e_PIXELFORMAT, const char* name, const char* path) {
    return engine->Texture_LoadCubemapHDRI(shader, size, e_PIXELFORMAT, name, path);
}

ShaderAsset* EngineAPI::Asset_LoadShader(RPShaderType type, const char* name, const char* vsPath, const char* fsPath) {
    return engine->Shader_Load(type, name, vsPath, fsPath);
}

ShaderAsset* EngineAPI::Asset_GetShader(unsigned int id) {
    return engine->Shader_Get(id);
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

void EngineAPI::RP_Model_Add(unsigned int id) {
    engine->RP_Model_Add(id);
}