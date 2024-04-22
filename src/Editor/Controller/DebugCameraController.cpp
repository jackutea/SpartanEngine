#include "DebugCameraController.h"

DebugCameraController::DebugCameraController() {
}

DebugCameraController::~DebugCameraController() {
}

void DebugCameraController::Inject(EditorContext *ctx) {
    this->ctx = ctx;
}

void DebugCameraController::Process(Engine *engine, float dt) {
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        Vector3 move = {0};
        if (IsKeyDown(KEY_W)) {
            move.z += 1;
        } else if (IsKeyDown(KEY_S)) {
            move.z -= 1;
        }
        if (IsKeyDown(KEY_A)) {
            move.x -= 1;
        } else if (IsKeyDown(KEY_D)) {
            move.x += 1;
        }
        CameraModel *mainCamera = engine->Camera_GetMain();
        mainCamera->Move(Vector3Scale(move, 10.0f * dt));
    }
}