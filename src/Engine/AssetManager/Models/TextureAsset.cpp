#include "TextureAsset.h"
#include <iostream>

TextureAsset::TextureAsset() {
    id = 0;
}

TextureAsset::~TextureAsset() {
    if (texture.id == 0) {
        UnloadTexture(texture);
    }
}

void TextureAsset::Load(const char *path) {
    try {
        texture = LoadTexture(path);
    } catch (...) {
        std::cout << "Loaded texture: " << path << std::endl;
    }
}
