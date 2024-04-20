#include "define.h"
#include "Engine/Engine.h"
#include "User/UserMain.h"

int main() {

    InitWindow(PublishSetting::SCREEN_WIDTH, PublishSetting::SCREEN_HEIGHT, PublishSetting::GAME_TITLE);

    SetTraceLogLevel(LOG_WARNING);

    Engine *engine = new Engine();
    engine->Initialize();

    UserMain *user = new UserMain();
    user->OnStart(engine->cmd);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        {
            // Engine Logic
            engine->LogicTick(dt);

            // User Logic
            user->OnLogicUpdate(engine->cmd, dt);
        }

        try {
            BeginDrawing();

            // Ready to draw
            user->OnReadyDraw(engine->cmd);

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