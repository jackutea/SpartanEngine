``` C
#include <raylib.h>
#include <iostream>
using namespace std::string_literals;

auto TITLE = u8"UTF-8 Sample";

int main() {

    InitWindow(800, 450, TITLE);

    auto txt = u8"你";
    int codepointsCount;
    int *codepoints = LoadCodepoints(txt, &codepointsCount);
    Font font = LoadFontEx("./assets/fonts/SIMHEI.TTF", 30, codepoints, codepointsCount);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTextEx(font, txt, {190, 100}, 30, 1, LIGHTGRAY);
        EndDrawing();
    }

    UnloadCodepoints(codepoints);
    UnloadFont(font);

    CloseWindow();

    return 0;
}
```