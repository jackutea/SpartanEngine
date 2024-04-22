#include "UserMain.h"

UserMain::UserMain() {
    ctx = new UserContext();
    restFixTime = 0;
}

UserMain::~UserMain() {
    delete ctx;
}

void UserMain::OnStart(EngineAPI* api) {
    // Model
    ModelAsset* model = api->Asset_LoadModel("Sphere", "assets/built_in/models/mesh_sphere.glb");
    auto tex = api->Asset_LoadTexture("white", "assets/built_in/textures/tex_white.png");
    auto sha = api->Asset_LoadShader("lit", "assets/user/glsl330/shader_vertex_lit.vs", "assets/user/glsl330/shader_vertex_lit.fs");
    model->SetTexture(0, MATERIAL_MAP_DIFFUSE, tex->texture);
    model->SetShader(0, sha->shader);

    ctx->model = model;
    ctx->tex = tex;
    ctx->sha = sha;

    // Sky
    SkyRenderer* sky = api->RP_GetSky();
    sky->solidColor = {17, 17, 17, 255};
}

void UserMain::OnLogicUpdate(EngineAPI* api, float dt) {

    // 1. Process Input
    // cam->Rotate({1 * dt, 1 * dt, 0});
    float off = (float)sin(GetTime()) * 2;

    // 2. Normal Logic Tick
    LightRenderer* light = api->RP_GetMainLight();
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 mouseDelta = GetMouseDelta();
        light->pos.x += mouseDelta.x * 0.01f;
        light->pos.y -= mouseDelta.y * 0.01f;
    }

    // CameraModel* cam = api->GetMainCamera();
    // cam->MoveTo({off, off, 0});
    // cam->Rotate({off * .5f, off * .5f, 0});

    // 3. Fix Logic Tick
    float fixInterval = UserSetting::FIXED_TIME_STEP;
    restFixTime += dt;
    if (restFixTime < fixInterval) {
        OnFixLogicUpdate(api, restFixTime);
        restFixTime = 0;
    } else {
        while (restFixTime >= fixInterval) {
            OnFixLogicUpdate(api, fixInterval);
            restFixTime -= fixInterval;
        }
    }
}

void UserMain::OnFixLogicUpdate(EngineAPI* api, float fixdt) {
}

// 添加至绘制列表
void UserMain::OnReadyDraw(EngineAPI* api) {
    api->RP_Model_Add(ctx->model);
}

// GUI
void UserMain::OnPostGUI(EngineAPI* api, float dt) {
    Font font = api->Font_GetDefault()->font;
    DrawTextEx(font, "你好World", {10, 10}, 30, 1, WHITE);
}