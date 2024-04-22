#include "EditorMain.h"

EditorMain::EditorMain() {
    debugCameraController = new DebugCameraController();
    ctx = new EditorContext();
}

EditorMain::~EditorMain() {
    delete debugCameraController;
    delete ctx;
}

void EditorMain::Inject(Engine *engine) {
    this->engine = engine;
    debugCameraController->Inject(ctx);
}

void EditorMain::Initialize() {
    std::cout << "EditorMain::Initialize()" << std::endl;
}

void EditorMain::ProcessUserInterface(float dt) {
    debugCameraController->Process(engine, dt);
}

void EditorMain::OnReadyDraw() {
}