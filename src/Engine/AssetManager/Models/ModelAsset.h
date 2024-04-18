#pragma once

#include "../import.h"

class ModelAsset {
public:
    int id;
    Model model;

public:
    ModelAsset();
    ~ModelAsset();
    void Load(const char *path);
    void Draw(Vector3 pos, Vector3 rotateAxis, float angle, Vector3 scale);
    void SetTexture(int matIndex, int texIndex, Texture2D texture);
    void SetShader(int matIndex, Shader shader);
};