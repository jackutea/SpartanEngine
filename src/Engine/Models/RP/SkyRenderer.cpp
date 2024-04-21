#include "SkyRenderer.h"

SkyRenderer::SkyRenderer() {
    skyType = RPSkyType::None;
    solidColor = WHITE;
    ambientColor = {50, 50, 50, 255};
}

SkyRenderer::~SkyRenderer() {
}