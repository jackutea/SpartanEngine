#ifndef ENGINE_CORE_FONT_FONTCORECONTEXT_H__
#define ENGINE_CORE_FONT_FONTCORECONTEXT_H__

#include "import.h"

class FontCoreContext {
public:
    FontAsset* defaultFont;

public:
    FontCoreContext();
    ~FontCoreContext();
};

#endif // ENGINE_CORE_FONT_FONTCORECONTEXT_H__