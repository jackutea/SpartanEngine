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
    ModelAsset* model = api->Asset_LoadModel("Sphere1", "assets/built_in/models/mesh_polyball.glb");
    ShaderAsset* sha = api->Asset_LoadShader(RPShaderType::Lit, "lit1", "assets/user/glsl330/shader_vertex_lit.vs", "assets/user/glsl330/shader_vertex_lit.fs");
    TextureAsset* tex = api->Asset_LoadTexture("white1", "assets/built_in/textures/tex_white.png");
    model->SetTexture(0, MATERIAL_MAP_DIFFUSE, tex->texture);
    model->SetShader(0, sha->shader);

    ctx->modelID = model->GetID();

    // Sky
    SkyRenderer* sky = api->RP_GetSky();
    sky->solidColor = {17, 17, 17, 255};
    sky->skyType = RPSkyType::Cubemap;
    ShaderAsset* sha2 = api->Asset_LoadShader(RPShaderType::Sky_Cubemap, "lit2", "assets/user/glsl330/shader_skybox.vs", "assets/user/glsl330/shader_skybox.fs");
    TextureAsset* tex2 = api->Asset_LoadCubemapTexture("white2", "assets/built_in/textures/skybox.png");
    sky->SetCubemap(sha2, tex2);

}

void UserMain::OnLogicUpdate(EngineAPI* api, float dt) {

    Vector2 moveAxis = PureFunctions::Input_GetKeyMoveAxis3D(KEY_W, KEY_S, KEY_A, KEY_D);
    ModelAsset* model = api->Asset_GetModel(ctx->modelID);
    model->tf.translation += (Vector3){moveAxis.x * dt, 0, moveAxis.y * dt};

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
    api->RP_Model_Add(ctx->modelID);
}

// GUI
void UserMain::OnPostGUI(EngineAPI* api, float dt) {
    Font font = api->Font_GetDefault()->font;
    DrawTextEx(font, "你好World", {10, 10}, 30, 1, WHITE);
}