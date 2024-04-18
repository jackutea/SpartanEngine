#include "define.h"
#include "Engine/Engine.h"
#include "User/UserMain.h"

int main() {

    Engine *engine = new Engine();
    engine->Initialize();

    UserMain *user = new UserMain();
    user->OnStart(engine->cmd);

    InitWindow(PublishSetting::SCREEN_WIDTH, PublishSetting::SCREEN_HEIGHT, PublishSetting::GAME_TITLE);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        {
            // Engine Logic
            engine->LogicTick(dt);
            
            // User Logic
            user->OnLogicUpdate(engine->cmd, dt);
        }

        {
            BeginDrawing();

            // Ready to draw
            user->OnReadyDraw(engine->cmd);

            // Draw
            engine->Render();

            // UI
            engine->ProcessAndRenderUI();

            EndDrawing();
        }
    }

    CloseWindow();

    user->OnQuit();

    delete user;
    delete engine;

    return 0;
}