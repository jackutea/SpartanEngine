#pragma once

#include "FontCoreContext.h"

class FontCore {
public:
    FontCoreContext *ctx;

public:
    FontCore();
    ~FontCore();
    void SetDefaultFont(FontAsset *fontAsset);
    FontAsset *GetDefaultFont();
};