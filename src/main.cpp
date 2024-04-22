#include "define.h"
#include "Engine/EngineAPI.h"
#include "Engine/Engine.h"
#include "User/UserMain.h"
#ifndef SPARTAN_RUNTIME_ONLY
#include "Editor/EditorMain.h"
#endif

int main() {

    InitWindow(UserSetting::SCREEN_WIDTH, UserSetting::SCREEN_HEIGHT, UserSetting::GAME_TITLE);

    SetTraceLogLevel(LOG_WARNING);

    // ==== Ctor ====
    EngineAPI *api = new EngineAPI();
    Engine *engine = new Engine();
    UserMain *user = new UserMain();
#ifndef SPARTAN_RUNTIME_ONLY
    EditorMain *editor = new EditorMain();
#endif

    // ==== Inject ====
    api->Inject(engine);
#ifndef SPARTAN_RUNTIME_ONLY
    editor->Inject(engine);
#endif

    try {

        // ==== Init ====
        engine->Initialize();
#ifndef SPARTAN_RUNTIME_ONLY
        editor->Initialize();
#endif

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
#ifndef SPARTAN_RUNTIME_ONLY
            // Editor Logic
            editor->ProcessUserInterface(dt);
#endif
            // Engine Logic
            engine->LogicTick(dt);

            // User Logic
            user->OnLogicUpdate(api, dt);
        } catch (...) {
            TraceLog(LOG_ERROR, "Logic Tick Error.");
        }

        try {
            BeginDrawing();

#ifndef SPARTAN_RUNTIME_ONLY
            // Editor Draw
            editor->OnReadyDraw();
#endif
            // Ready to draw
            user->OnReadyDraw(api);

            // Draw
            engine->Render();

            // UI
            user->OnPostGUI(api, dt);
            engine->ProcessAndRenderUI();

            EndDrawing();
        } catch (...) {
            TraceLog(LOG_ERROR, "Render Tick Error.");
        }
    }

    CloseWindow();

    delete user;
    delete engine;
    delete api;
#ifndef SPARTAN_RUNTIME_ONLY
    delete editor;
#endif

    return 0;
}