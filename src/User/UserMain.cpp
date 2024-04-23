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
    ModelAsset* model = api->Asset_LoadModel("Sphere", "assets/built_in/models/mesh_polyball.glb");
    SLog("Count %d\r\n", model->model.materialCount);
    
    ModelAsset* model2 = api->Asset_LoadModel("Sphere", "assets/built_in/models/mesh_polysphere.glb");
    // model2->model = LoadModelFromMesh(GenMeshSphere(1, 32, 32));
    SLog("Count %d\r\n", model2->model.materialCount);

    auto tex = api->Asset_LoadTexture("white", "assets/built_in/textures/tex_white.png");
    auto sha = api->Asset_LoadShader("lit", "assets/user/glsl330/shader_vertex_lit.vs", "assets/user/glsl330/shader_vertex_lit.fs");
    // auto sha2 = api->Asset_LoadShader("lit2", "assets/user/glsl330/shader_vertex_lit.vs", "assets/user/glsl330/shader_vertex_lit.fs");

    // 上各种贴图
    model->SetTexture(0, MATERIAL_MAP_DIFFUSE, tex->texture);
    model->SetShader(0, sha->shader);

    model2->SetTexture(0, MATERIAL_MAP_DIFFUSE, tex->texture);
    model2->SetShader(0, sha->shader);

    ctx->model = model;
    ctx->model2 = model2;
    ctx->tex = tex;
    ctx->sha = sha;

    // Sky
    SkyRenderer* sky = api->RP_GetSky();
    sky->solidColor = {17, 17, 17, 255};

}

void UserMain::OnLogicUpdate(EngineAPI* api, float dt) {

    Vector2 moveAxis = PureFunctions::Input_GetKeyMoveAxis3D(KEY_W, KEY_S, KEY_A, KEY_D);
    ctx->model->tf.translation += (Vector3){moveAxis.x * dt, 0, moveAxis.y * dt};

    // 1. Process Input
    CameraModel* camera = api->Camera_GetMain();
    // camera->Move({0, 0, 1*dt});

    // 2. Normal Logic Tick
    LightRenderer* light = api->RP_GetMainLight();
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 mouseDelta = GetMouseDelta();
        light->pos.x += mouseDelta.x * 0.01f;
        light->pos.y -= mouseDelta.y * 0.01f;
    }

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
    // Fixed Logic Tick

    // Physics Simulation
}

// 添加至绘制列表
void UserMain::OnReadyDraw(EngineAPI* api) {
    api->RP_Model_Add(ctx->model2);
    api->RP_Model_Add(ctx->model);
}

// GUI
void UserMain::OnPostGUI(EngineAPI* api, float dt) {
    Font font = api->Font_GetDefault()->font;
    DrawTextEx(font, "你好World", {10, 10}, 30, 1, WHITE);
}