#pragma once

#include "EditorContext.h"
#include "Controller/DebugCameraController.h"
#include "import.h"

class EditorMain {
private:
    DebugCameraController *debugCameraController;
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