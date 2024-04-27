#ifndef ENGINE_ENGINE_H__
#define ENGINE_ENGINE_H__

#include "EngineContext.h"
#include "Domain/export.h"

class Engine {
private:
    EngineContext* ctx;

public:
    Engine();
    ~Engine();

#pragma region LifeCycle
    void Initialize();
    void OnLogicUpdate(float dt);
    void Render();
    void ProcessAndRenderUI();
#pragma endregion

#pragma region Light
    LightRenderer* Light_Create(LightType type);
    LightRenderer* Light_GetMain();
#pragma endregion

#pragma region Sky
    SkyRenderer* Sky_GetMain();
#pragma endregion

#pragma region Camera
    CameraModel* Camera_Create();
    void Camera_SetMain(CameraModel* camera);
    CameraModel* Camera_GetMain();
#pragma endregion

#pragma region Model
    ModelAsset* Model_Load(const char* name, const char* path);
    ModelAsset* Model_Get(unsigned int id);
#pragma endregion

#pragma region Texture
    TextureAsset* Texture_Load(const char* name, const char* path);
    TextureAsset* Texture_Get(unsigned int id);
    TextureAsset* Texture_LoadCubemap(const char* name, const char* path);
    TextureAsset* Texture_LoadCubemapHDRI(Shader shader, int size, int e_PIXELFORMAT, const char* name, const char* path);
#pragma endregion

#pragma region Shader
    ShaderAsset* Shader_Load(RPShaderType type, const char* name, const char* vsPath, const char* fsPath);
    ShaderAsset* Shader_Get(unsigned int id);
    void Shader_Reload(ShaderAsset* shader);
    void Shader_ReloadAll();
#pragma endregion

#pragma region Font
    FontAsset* Font_Load(const char* path);
    FontAsset* Font_LoadWithUTF8(const char* path, int size, const char* unicodeText);
    void Font_SetDefault(FontAsset* font);
    FontAsset* Font_GetDefault();
#pragma endregion

#pragma region RP
    void RP_Model_Add(ModelAsset* model);
    void RP_Model_Add(unsigned int id);
#pragma endregion
};

#endif // ENGINE_ENGINE_H__