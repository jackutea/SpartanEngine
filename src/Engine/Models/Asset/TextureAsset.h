#pragma once

#include "../import.h"

class TextureAsset {
public:
    unsigned int id;
    Texture texture;

public:
    TextureAsset();
    ~TextureAsset();
    unsigned int GetID();
    void Load(const char *path);
};