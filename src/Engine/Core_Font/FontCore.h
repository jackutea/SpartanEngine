#ifndef ENGINE_CORE_FONT_FONT_CORE_H__
#define ENGINE_CORE_FONT_FONT_CORE_H__

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

#endif // ENGINE_CORE_FONT_FONT_CORE_H__