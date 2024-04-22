#pragma once

#include "../import.h"

class FontAsset {
public:
    int id;
    Font font;
    int *codePoints;

public:
    FontAsset();
    ~FontAsset();
    void Load(const char *path);
    void LoadWithUTF8(const char *path, int size, const char *unicodeText);
};