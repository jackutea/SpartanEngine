#include "define.h"
#include "Engine/Engine.h"
#include "User/UserMain.h"

int main() {

    Engine *engine = new Engine();
    engine->LoadBuiltInAssets();

    UserMain *user = new UserMain();
    user->OnStart(engine->cmd);

    InitWindow(PublishSetting::SCREEN_WIDTH, PublishSetting::SCREEN_HEIGHT, PublishSetting::GAME_TITLE);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        {
            // User Logic
            user->OnLogicUpdate(engine->cmd, dt);
        }

        {
            BeginDrawing();

            // Ready to draw
            user->OnReadyDraw(engine->cmd);

            // Draw
            engine->Render();

            EndDrawing();
        }
    }

    CloseWindow();

    user->OnQuit();

    delete user;
    delete engine;

    return 0;
}