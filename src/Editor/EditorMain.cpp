#include "EditorMain.h"

EditorMain::EditorMain() {
    shortcutController = new ShortcutController();
    ctx = new EditorContext();
}

EditorMain::~EditorMain() {
    delete shortcutController;
    delete ctx;
}

void EditorMain::Inject(Engine *engine) {
    this->engine = engine;
    shortcutController->Inject(ctx);
}

void EditorMain::Initialize() {
}

void EditorMain::ProcessUserInterface(float dt) {
    shortcutController->Process(engine, dt);
}

void EditorMain::OnReadyDraw() {
}