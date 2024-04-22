#include "FontAsset.h"
#include "../import.h"

FontAsset::FontAsset() {
}

FontAsset::~FontAsset() {
    if (codePoints != nullptr) {
        UnloadCodepoints(codePoints);
    }
    if (font.glyphs != nullptr) {
        UnloadFont(font);
    }
}

void FontAsset::Load(const char *path) {
    font = LoadFont(path);
}

void FontAsset::LoadWithUTF8(const char *path, int size, const char *unicodeText) {
    int count;
    codePoints = LoadCodepoints(unicodeText, &count);
    font = LoadFontEx(path, size, codePoints, count);
}