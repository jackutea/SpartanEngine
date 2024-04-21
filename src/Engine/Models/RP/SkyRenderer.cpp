#include "SkyRenderer.h"

SkyRenderer::SkyRenderer() {
    skyType = RPSkyType::None;
    solidColor = WHITE;
    ambientColor = (Color){20, 20, 20};
}

SkyRenderer::~SkyRenderer() {
}