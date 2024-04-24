#ifndef ENGINE_MODEL_SKY_RENDERER_H__
#define ENGINE_MODEL_SKY_RENDERER_H__

#include "../import.h"

class SkyRenderer {
public:
    RPSkyType skyType;
    Color solidColor;
    Color ambientColor;

public:
    SkyRenderer();
    ~SkyRenderer();
};

#endif // ENGINE_MODEL_SKY_RENDERER_H__