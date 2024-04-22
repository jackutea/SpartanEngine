#pragma once

#include "../EditorContext.h"
#include "../import.h"

class DebugCameraController {
private:
    EditorContext *ctx;

public:
    DebugCameraController();
    ~DebugCameraController();
    void Inject(EditorContext *ctx);
    void Process(Engine *engine, float dt);
};