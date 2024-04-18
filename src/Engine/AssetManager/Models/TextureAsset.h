#pragma once

#include "../import.h"

class TextureAsset {
public:
    int id;
    Texture texture;

public:
    TextureAsset();
    ~TextureAsset();
    void Load(const char *path);
};