#pragma once

#include "EditorContext.h"
#include "Controller/ShortcutController.h"
#include "import.h"

class EditorMain {
private:
    ShortcutController *shortcutController;
    EditorContext *ctx;
    Engine *engine;

public:
    EditorMain();
    ~EditorMain();
    void Inject(Engine *engine);
    void Initialize();
    void ProcessUserInterface(float dt);
    void OnReadyDraw();
};