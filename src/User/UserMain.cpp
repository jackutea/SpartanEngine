#include "UserMain.h"

UserMain::UserMain() {
    ctx = new UserContext();
    restFixTime = 0;
}

UserMain::~UserMain() {
    delete ctx;
}

void UserMain::OnStart(EngineCommand* cmd) {
    auto asset = cmd->GetAssetManager();
    auto model = asset->LoadModel("assets/built_in/models/mesh_sphere.glb");
    auto tex = asset->LoadTexture("assets/built_in/textures/tex_white.png");
    auto sha = cmd->LoadShader("lit", "assets/user/glsl330/shader_vertex_lit.vs", "assets/user/glsl330/shader_vertex_lit.fs");
    model->SetTexture(0, MATERIAL_MAP_DIFFUSE, tex->texture);
    model->SetShader(0, sha->shader);

    ctx->model = model;
    ctx->tex = tex;
    ctx->sha = sha;
}

void UserMain::OnLogicUpdate(EngineCommand* cmd, float dt) {

    // 1. Process Input
    // cam->Rotate({1 * dt, 1 * dt, 0});
    float off = (float)sin(GetTime()) * 2;

    // 2. Normal Logic Tick
    LightRenderer* light = cmd->RP_GetMainLight();
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 mouseDelta = GetMouseDelta();
        light->pos.x += mouseDelta.x * 0.01f;
        light->pos.y -= mouseDelta.y * 0.01f;
    }

    CameraModel* cam = cmd->GetMainCamera();
    cam->MoveTo({off, off, 0});

    // 3. Fix Logic Tick
    float fixInterval = PublishSetting::FIXED_TIME_STEP;
    restFixTime += dt;
    if (restFixTime < fixInterval) {
        OnFixLogicUpdate(cmd, restFixTime);
        restFixTime = 0;
    } else {
        while (restFixTime >= fixInterval) {
            OnFixLogicUpdate(cmd, fixInterval);
            restFixTime -= fixInterval;
        }
    }
}

void UserMain::OnFixLogicUpdate(EngineCommand* cmd, float fixdt) {
}

// 仅设置, 没绘制
void UserMain::OnReadyDraw(EngineCommand* cmd) {
    cmd->RP_Sky_SetSolid({17, 17, 17, 255});

    cmd->RP_Model_Add(ctx->model);
}

void UserMain::OnQuit() {
    // 释放资源
}