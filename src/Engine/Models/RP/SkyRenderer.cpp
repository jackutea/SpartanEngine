#include "SkyRenderer.h"

SkyRenderer::SkyRenderer() {
    skyType = RPSkyType::None;
    solidColor = WHITE;
    ambientColor = {20, 20, 20, 255};
}

SkyRenderer::~SkyRenderer() {
}