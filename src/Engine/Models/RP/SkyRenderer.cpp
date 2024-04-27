#include "SkyRenderer.h"

SkyRenderer::SkyRenderer() {
    skyType = RPSkyType::None;
    solidColor = WHITE;
    ambientColor = {50, 50, 50, 255};
}

SkyRenderer::~SkyRenderer() {
}

void SkyRenderer::SetCubemap(ShaderAsset *shader, TextureAsset *cubemap) {
    skyboxModel->SetTexture(0, MATERIAL_MAP_CUBEMAP, cubemap->texture);
    skyboxModel->SetShader(0, shader->shader);

    int envMap = MATERIAL_MAP_CUBEMAP;
    SetShaderValue(skyboxModel->model.materials[0].shader, GetShaderLocation(skyboxModel->model.materials[0].shader, "environmentMap"), &envMap,
                   SHADER_UNIFORM_INT);
}