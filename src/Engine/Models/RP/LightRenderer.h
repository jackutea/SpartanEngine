#pragma once

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