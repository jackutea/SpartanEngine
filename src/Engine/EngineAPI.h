#ifndef ENGINE_ENGINEAPI_H__
#define ENGINE_ENGINEAPI_H__

#include "Engine.h"

class EngineAPI {
private:
    Engine* engine;

public:
    EngineAPI();
    ~EngineAPI();

    void Inject(Engine* engine);

    SPTAPI void Test_ForScripts();

    // ==== Asset ====
    ModelAsset* Asset_LoadModel(const char* name, const char* path);
    ModelAsset* Asset_GetModel(unsigned int id);
    TextureAsset* Asset_LoadTexture(const char* name, const char* path);
    TextureAsset* Asset_GetTexture(unsigned int id);
    TextureAsset* Asset_LoadCubemapTexture(const char* name, const char* path);
    TextureAsset* Asset_LoadCubemapHDRI(Shader shader, int size, int e_PIXELFORMAT, const char* name, const char* path);
    ShaderAsset* Asset_LoadShader(RPShaderType type, const char* name, const char* vsPath, const char* fsPath);
    ShaderAsset* Asset_GetShader(unsigned int id);
    void Asset_ReloadShader(ShaderAsset* shader);
    void Asset_ReloadAllShader();
    FontAsset* Asset_LoadFont(const char* path);

    // ==== Font ====
    void Font_SetDefault(FontAsset* font);
    FontAsset* Font_GetDefault();

    // ==== Camera ====
    CameraModel* Camera_GetMain();

    // ==== RP ====
    LightRenderer* RP_GetMainLight();
    SkyRenderer* RP_GetSky();
    void RP_Model_Add(ModelAsset* model);
    void RP_Model_Add(unsigned int modelID);
};

#endif // ENGINE_ENGINEAPI_H__