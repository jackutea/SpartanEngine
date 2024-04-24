#ifndef ENGINE_ASSETMANAGER_ASSETMANAGER_H__
#define ENGINE_ASSETMANAGER_ASSETMANAGER_H__

#include "import.h"
#include "AssetManagerContext.h"

class AssetManager {
public:
    AssetManagerContext *ctx;

public:
    AssetManager();
    ~AssetManager();

    ModelAsset *Model_Load(const char *name, const char *path);
    ModelAsset *Model_GetByID(unsigned int id);
    void Model_Unload(unsigned int id);

    TextureAsset *Texture_Load(const char *path);
    TextureAsset *Texture_GetByID(unsigned int id);
    void Texture_Unload(unsigned int id);

    ShaderAsset *Shader_Load(const char *name, const char *vsPath, const char *fsPath);
    ShaderAsset *Shader_GetByID(unsigned int id);
    ShaderAsset *Shader_GetByName(const char *name);
    void Shader_Unload(unsigned int id);
    void Shader_Unload(const char *name);

    FontAsset *Font_Load(const char *path);
    FontAsset *Font_LoadWithUTF8(const char *path, int size, const char *unicodeText);
    FontAsset *Font_GetByID(int id);
};

#endif // ENGINE_ASSETMANAGER_ASSETMANAGER_H__