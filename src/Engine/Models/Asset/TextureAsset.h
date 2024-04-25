#ifndef ENGINE_MODEL_TEXTURE_ASSET_H__
#define ENGINE_MODEL_TEXTURE_ASSET_H__

#include "../import.h"

class TextureAsset {
public:
    unsigned int id;
    Texture texture;

public:
    TextureAsset();
    ~TextureAsset();
    unsigned int GetID();
    void Load(const char *path);
    void LoadCubemap_SPT(const char *name, const char *path);
    void LoadCubemapHDRI(Shader shader, int size, int e_PIXELFORMAT, const char *name, const char *path);
};

#endif // ENGINE_MODEL_TEXTURE_ASSET_H__