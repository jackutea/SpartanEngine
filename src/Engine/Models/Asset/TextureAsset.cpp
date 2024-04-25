#include "TextureAsset.h"
#include <iostream>

TextureAsset::TextureAsset() {
}

TextureAsset::~TextureAsset() {
    if (texture.id == 0) {
        UnloadTexture(texture);
    }
}

unsigned int TextureAsset::GetID() {
    return texture.id;
}

void TextureAsset::Load(const char *path) {
    try {
        texture = LoadTexture(path);
    } catch (...) {
        std::cerr << "Loaded texture: " << path << std::endl;
    }
}

void TextureAsset::LoadCubemapVertical(const char *name, const char *path) {
    try {
        Image image = LoadImage(path);
        texture = LoadTextureCubemap(image, CUBEMAP_LAYOUT_LINE_VERTICAL);
        UnloadImage(image);
    } catch (...) {
        std::cerr << "Loaded cubemap texture: " << path << std::endl;
    }
}
