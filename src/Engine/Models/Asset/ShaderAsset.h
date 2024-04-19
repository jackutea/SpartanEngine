#pragma once

#include "../import.h"

class ShaderAsset {
public:
    unsigned int id;
    Shader shader;

public:
    ShaderAsset();
    ~ShaderAsset();
    unsigned int GetID();
    void Load(const char *vsPath, const char *fsPath);
};