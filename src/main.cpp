#include "define.h"
#include "Engine/EngineCommand.h"
#include "Engine/Engine.h"
#include "User/UserMain.h"

int main() {

    InitWindow(PublishSetting::SCREEN_WIDTH, PublishSetting::SCREEN_HEIGHT, PublishSetting::GAME_TITLE);

    SetTraceLogLevel(LOG_WARNING);

    // ==== Ctor ====
    EngineCommand *cmd = new EngineCommand();
    Engine *engine = new Engine();
    UserMain *user = new UserMain();

    // ==== Inject ====
    cmd->Inject(engine);

    try {

        // ==== Init ====
        engine->Initialize();

        // ==== Start ====
        user->OnStart(cmd);

    } catch (...) {
        TraceLog(LOG_ERROR, "An error occurred in the initialization.");
        CloseWindow();
        return 1;
    }

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        {
            // Engine Logic
            engine->LogicTick(dt);

            // User Logic
            user->OnLogicUpdate(cmd, dt);
        }

        try {
            BeginDrawing();

            // Ready to draw
            user->OnReadyDraw(cmd);

            // Draw
            engine->Render();

            // UI
            engine->ProcessAndRenderUI();

            EndDrawing();
        } catch (...) {
            TraceLog(LOG_ERROR, "An error occurred in the main loop.");
        }
    }

    CloseWindow();

    user->OnQuit();

    delete user;
    delete engine;

    return 0;
}