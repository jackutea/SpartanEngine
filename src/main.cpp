#include "define.h"
#include "PublishSetting.h"
#include "Engine/export.h"
#include "User/UserMain.h"

int main() {

    Engine *engine = new Engine();
    engine->LoadBuiltInAssets();

    UserMain *user = new UserMain();
    user->OnStart();

    InitWindow(PublishSetting::SCREEN_WIDTH, PublishSetting::SCREEN_HEIGHT, PublishSetting::GAME_TITLE);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        {
            // User Logic
            user->OnLogicUpdate(dt);
        }

        {
            BeginDrawing();

            // Ready to draw
            user->OnReadyDraw();

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