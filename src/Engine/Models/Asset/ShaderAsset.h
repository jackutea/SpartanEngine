#pragma once

#include "../import.h"

class ShaderAsset {
public:
    unsigned int id;
    Shader shader;

    // Shader locations
    int lit_enabledLoc;
    int lit_typeLoc;
    int lit_positionLoc;
    int lit_targetLoc;
    int lit_colorLoc;
    int lit_attenuationLoc;
    int lit_countLoc;
    int ambientLoc;

private:
    char *name;

public:
    ShaderAsset();
    ~ShaderAsset();
    unsigned int GetID();
    const char *GetName();
    void Load(const char *name, const char *vsPath, const char *fsPath);
    void InitLocs(int lightIndex);
    void SetValue(int locIndex, void *value, int uniformType);
};