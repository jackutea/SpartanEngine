#include "FontCore.h"

FontCore::FontCore() {
    ctx = new FontCoreContext();
}

FontCore::~FontCore() {
    delete ctx;
}

void FontCore::SetDefaultFont(FontAsset *fontAsset) {
    ctx->defaultFont = fontAsset;
}

FontAsset *FontCore::GetDefaultFont() {
    return ctx->defaultFont;
}