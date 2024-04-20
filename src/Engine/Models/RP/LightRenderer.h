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

    // Shader locations
    int enabledLoc;
    int typeLoc;
    int positionLoc;
    int targetLoc;
    int colorLoc;
    int attenuationLoc;

public:
    LightRenderer();
    ~LightRenderer();

    void SetupShader(Shader shader);
    void UpdateShader(Shader shader);
};