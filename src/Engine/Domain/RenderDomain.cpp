#include "RenderDomain.h"

namespace RenderDomain {

// Light
static void PrepareShader_Lit(EngineContext *ctx, ShaderAsset *shader) {
    int lightCount = ctx->rp->ctx->lights->size();
    for (auto light : *ctx->rp->ctx->lights) {

        int fisEnable = light->isEnable ? 1 : 0;
        shader->SetValue(shader->lit_enabledLoc, &fisEnable, SHADER_UNIFORM_INT);

        int ftype = (int)light->type;
        shader->SetValue(shader->lit_typeLoc, &ftype, SHADER_UNIFORM_INT);

        Vector3 pos = light->pos;
        float fpos[3] = {pos.x, pos.y, pos.z};
        shader->SetValue(shader->lit_positionLoc, &fpos, SHADER_UNIFORM_VEC3);

        Vector3 target = light->target;
        float ftarget[3] = {target.x, target.y, target.z};
        shader->SetValue(shader->lit_targetLoc, &ftarget, SHADER_UNIFORM_VEC3);

        Color color = light->color;
        float fcolor[4] = {(float)color.r / (float)255, (float)color.g / (float)255, (float)color.b / (float)255, (float)color.a / (float)255};
        shader->SetValue(shader->lit_colorLoc, &fcolor, SHADER_UNIFORM_VEC4);

        float attenuation = light->attenuation;
        shader->SetValue(shader->lit_attenuationLoc, &attenuation, SHADER_UNIFORM_FLOAT);
    }
    shader->SetValue(shader->lit_countLoc, &lightCount, SHADER_UNIFORM_INT);

    // Ambient
    Color ambient = ctx->rp->ctx->sky->ambientColor;
    float fambient[4] = {(float)ambient.r / (float)255, (float)ambient.g / (float)255, (float)ambient.b / (float)255, (float)ambient.a / (float)255};
    shader->SetValue(shader->ambientLoc, &fambient, SHADER_UNIFORM_VEC4);

}

void PrepareShader(EngineContext *ctx) {
    Vector3 viewPos = ctx->cameraManager->GetMainCamera()->GetPosition();
    float fviewPos[3] = {viewPos.x, viewPos.y, viewPos.z};

    for (auto &kv : *ctx->assetManager->ctx->shaders) {
        ShaderAsset *shader = kv.second;
        RPShaderType type = shader->type;
        if (type == RPShaderType::Lit) {
            PrepareShader_Lit(ctx, shader);
        } else if (type == RPShaderType::Sky_Cubemap) {
        }

        // ViewPos
        shader->SetValue(shader->shader.locs[SHADER_LOC_VECTOR_VIEW], fviewPos, SHADER_UNIFORM_VEC3);
    }
}

} // namespace RenderDomain