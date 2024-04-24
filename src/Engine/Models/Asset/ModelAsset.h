#ifndef ENGINE_MODEL_MODEL_ASSET_H__
#define ENGINE_MODEL_MODEL_ASSET_H__

#include "../import.h"

class ModelAsset {
public:
    unsigned int id;
    Transform tf;
    Model model;

public:
    ModelAsset();
    ~ModelAsset();
    unsigned int GetID();
    void Load(const char *path);
    void Draw();
    void SetTexture(int matIndex, int texIndex, Texture2D texture);
    void SetShader(int matIndex, Shader shader);
    void Log();
};

#endif // ENGINE_MODEL_MODEL_ASSET_H__