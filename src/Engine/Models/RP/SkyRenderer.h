#ifndef ENGINE_MODEL_SKY_RENDERER_H__
#define ENGINE_MODEL_SKY_RENDERER_H__

#include "../import.h"
#include "../Asset/ShaderAsset.h"
#include "../Asset/ModelAsset.h"
#include "../Asset/TextureAsset.h"

class ModelAsset;
class TextureAsset;

class SkyRenderer {
public:
    RPSkyType skyType;
    Color solidColor;
    Color ambientColor;
    ModelAsset *skyboxModel;

public:
    SkyRenderer();
    ~SkyRenderer();
    void SetCubemap(ShaderAsset* shader, TextureAsset *cubemap);
};

#endif // ENGINE_MODEL_SKY_RENDERER_H__