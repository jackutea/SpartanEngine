#pragma once

#include "EditorContext.h"
#include "../Engine/Engine.h"

class EditorMain {
private:
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