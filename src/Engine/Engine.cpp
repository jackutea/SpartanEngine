#include "Engine.h"
#include <iostream>

Engine::Engine() {
    ctx = new EngineContext();
}

Engine::~Engine() {
    delete ctx;
}

#pragma region LifeCycle
void Engine::Initialize() {
    // Load built-in assets

    // Camera
    ctx->cameraManager->Initialize();

    // RP
    ctx->rp->Initialize();
}

void Engine::LogicTick(float dt) {
    // Update Logic here
    // ctx->cameraManager->cam3D->target.x += 100 * dt;
}

void Engine::Render() {

    // [ Camera Mode Begin
    ctx->cameraManager->Begin();

    // Prepare Shader
    {
        Vector3 viewPos = ctx->cameraManager->GetMainCamera()->GetPosition();

        int lightCount = ctx->rp->ctx->lights->size();
        for (auto &kv : *ctx->assetManager->ctx->shaders) {
            ShaderAsset *shader = kv.second;

            // Light
            for (auto light : *ctx->rp->ctx->lights) {
                shader->SetValue(shader->lit_enabledLoc, &light->isEnable, SHADER_UNIFORM_INT);

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

            // ViewPos
            shader->SetValue(shader->viewPosLoc, &viewPos, SHADER_UNIFORM_VEC3);

            // Ambient
            Color ambient = ctx->rp->ctx->sky->ambientColor;
            float fambient[4] = {(float)ambient.r / (float)255, (float)ambient.g / (float)255, (float)ambient.b / (float)255, (float)ambient.a / (float)255};
            shader->SetValue(shader->ambientLoc, &fambient, SHADER_UNIFORM_VEC4);
        }
    }

    // Render Skybox
    CameraModel *mainCam = ctx->cameraManager->GetMainCamera();
    RenderPipeline *rp = ctx->rp;
    rp->RenderAll(*mainCam);

    // ] Camera Mode End
    ctx->cameraManager->End();
}

void Engine::ProcessAndRenderUI() {
    // Process and Render UI here
    ctx->ui->ProcessAndRender();
}
#pragma endregion

#pragma region Light
LightRenderer *Engine::Light_Create(LightType type) {
    LightRenderer *light = ctx->rp->Light_Create(type);

    for (auto &kv : *ctx->assetManager->ctx->shaders) {
        ShaderAsset *shader = kv.second;
        int index = light->index;
        shader->InitLocs(index);
    }

    return light;
}
#pragma endregion

#pragma region Shader
ShaderAsset *Engine::Shader_Load(const char *name, const char *vsPath, const char *fsPath) {

    ShaderAsset *shader = ctx->assetManager->LoadShader(name, vsPath, fsPath);

    for (auto light : *ctx->rp->ctx->lights) {
        int index = light->index;
        shader->InitLocs(index);
    }

    return shader;
}
#pragma endregion