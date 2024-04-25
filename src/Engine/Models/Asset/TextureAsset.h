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
    void LoadCubemapVertical(const char *name, const char *path);
};

#endif // ENGINE_MODEL_TEXTURE_ASSET_H__