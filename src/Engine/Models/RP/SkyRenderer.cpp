#include "SkyRenderer.h"
#include "../Asset/ModelAsset.h"

SkyRenderer::SkyRenderer() {
    skyType = RPSkyType::None;
    solidColor = WHITE;
    ambientColor = {50, 50, 50, 255};
}

SkyRenderer::~SkyRenderer() {
    if (skyboxModel != nullptr) {
        delete skyboxModel;
    }
}