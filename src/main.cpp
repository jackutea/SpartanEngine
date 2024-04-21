#include "define.h"
#include "Engine/EngineAPI.h"
#include "Engine/Engine.h"
#include "User/UserMain.h"

int main() {

    InitWindow(PublishSetting::SCREEN_WIDTH, PublishSetting::SCREEN_HEIGHT, PublishSetting::GAME_TITLE);

    SetTraceLogLevel(LOG_WARNING);

    // ==== Ctor ====
    EngineAPI *api = new EngineAPI();
    Engine *engine = new Engine();
    UserMain *user = new UserMain();

    // ==== Inject ====
    api->Inject(engine);

    try {

        // ==== Init ====
        engine->Initialize();

        // ==== Start ====
        user->OnStart(api);

    } catch (...) {
        TraceLog(LOG_ERROR, "Init Error.");
        CloseWindow();
        return 1;
    }

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        try {
            // Engine Logic
            engine->LogicTick(dt);

            // User Logic
            user->OnLogicUpdate(api, dt);
        } catch (...) {
            TraceLog(LOG_ERROR, "Logic Tick Error.");
        }

        try {
            BeginDrawing();

            // Ready to draw
            user->OnReadyDraw(api);

            // Draw
            engine->Render();

            // UI
            engine->ProcessAndRenderUI();

            EndDrawing();
        } catch (...) {
            TraceLog(LOG_ERROR, "Render Tick Error.");
        }
    }

    CloseWindow();

    user->OnQuit();

    delete user;
    delete engine;

    return 0;
}