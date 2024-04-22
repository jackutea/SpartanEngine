#include "DebugCameraController.h"

DebugCameraController::DebugCameraController() {
}

DebugCameraController::~DebugCameraController() {
}

void DebugCameraController::Inject(EditorContext *ctx) {
    this->ctx = ctx;
}

void DebugCameraController::Process(Engine *engine, float dt) {
    if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_F1)) {
        ctx->isDebugCameraEnabled = !ctx->isDebugCameraEnabled;
    }
    if (ctx->isDebugCameraEnabled && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {

        CameraModel *mainCamera = engine->Camera_GetMain();
        Vector3 cameraFwd = mainCamera->GetForward();
        Vector3 cameraRight = Vector3CrossProduct(cameraFwd, (Vector3){0, 1, 0});

        float *multiply = &ctx->debugCameraSpeedMultiply;
        float wheel = GetMouseWheelMove();
        *multiply += wheel * 60 * dt;
        float rotateSpeed = 50 * (*multiply);
        float xMoveSpeed = 4 * (*multiply);
        float zMoveSpeed = 10 * (*multiply);

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

        Vector3 moveX = Vector3Scale(cameraRight, move.x);
        Vector3 moveZ = Vector3Scale(cameraFwd, move.z);
        move = Vector3Add(moveX, moveZ);
        move = Vector3Normalize(move);
        move.x *= xMoveSpeed;
        move.z *= zMoveSpeed;

        Vector2 rotateV2 = Vector2Scale(GetMouseDelta(), rotateSpeed);
        Vector3 rotate = {-rotateV2.x, -rotateV2.y, 0};

        mainCamera->Move(Vector3Scale(move, dt));
        mainCamera->Rotate(Vector3Scale(rotate, dt));
    }
}