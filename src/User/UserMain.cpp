#include "UserMain.h"

UserMain::UserMain() {
    ctx = new UserContext();
    restFixTime = 0;
}

UserMain::~UserMain() {
    delete ctx;
}

void UserMain::OnStart(EngineAPI* cmd) {
    // Model
    ModelAsset* model = cmd->Asset_LoadModel("Sphere", "assets/built_in/models/mesh_sphere.glb");
    auto tex = cmd->Asset_LoadTexture("white", "assets/built_in/textures/tex_white.png");
    auto sha = cmd->Asset_LoadShader("lit", "assets/user/glsl330/shader_vertex_lit.vs", "assets/user/glsl330/shader_vertex_lit.fs");
    model->SetTexture(0, MATERIAL_MAP_DIFFUSE, tex->texture);
    model->SetShader(0, sha->shader);

    ctx->model = model;
    ctx->tex = tex;
    ctx->sha = sha;

    // Sky
    SkyRenderer* sky = cmd->RP_GetSky();
    sky->solidColor = {17, 17, 17, 255};
}

void UserMain::OnLogicUpdate(EngineAPI* cmd, float dt) {

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

    // CameraModel* cam = cmd->GetMainCamera();
    // cam->MoveTo({off, off, 0});
    // cam->Rotate({off * .5f, off * .5f, 0});

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

void UserMain::OnFixLogicUpdate(EngineAPI* cmd, float fixdt) {
}

// 添加至绘制列表
void UserMain::OnReadyDraw(EngineAPI* cmd) {
    cmd->RP_Model_Add(ctx->model);
}