#ifndef ENGINE_MODEL_LIGHT_RENDERER_H__
#define ENGINE_MODEL_LIGHT_RENDERER_H__

#include "../import.h"

class LightRenderer {
public:
    int index;
    LightType type;
    bool isEnable;
    Vector3 pos;
    Vector3 target;
    Color color;
    float attenuation;

public:
    LightRenderer();
    ~LightRenderer();
};

#endif // ENGINE_MODEL_LIGHT_RENDERER_H__