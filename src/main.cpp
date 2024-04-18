#include <iostream>
#include "User/UserMain.h"
#include "define.h"

using namespace std::string_literals;
auto TITLE = u8"你, World!";

int main() {

    UserMain *user = new UserMain();
    user->OnStart();

    InitWindow(800, 450, TITLE);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        user->OnLogicUpdate(dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

    user->OnQuit();

    delete user;

    return 0;
}