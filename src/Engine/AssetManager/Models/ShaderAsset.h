#pragma once

#include "../import.h"

class ShaderAsset {
public:
    int id;
    Shader shader;

public:
    ShaderAsset();
    ~ShaderAsset();
    void Load(const char *vsPath, const char *fsPath);
};