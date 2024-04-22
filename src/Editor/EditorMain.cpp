#include "EditorMain.h"

EditorMain::EditorMain() {
    ctx = new EditorContext();
}

EditorMain::~EditorMain() {
    delete ctx;
}

void EditorMain::Inject(Engine *engine) {
    this->engine = engine;
}

void EditorMain::Initialize() {
    std::cout << "EditorMain::Initialize()" << std::endl;
}

void EditorMain::ProcessUserInterface(float dt) {
}

void EditorMain::OnReadyDraw() {
}