#include "ShortcutController.h"

ShortcutController::ShortcutController() {
}

ShortcutController::~ShortcutController() {
}

void ShortcutController::Inject(EditorContext *ctx) {
    this->ctx = ctx;
}

// When MouseRightDown, WSAD to move, mouse to rotate
static void ProcessDebugCamera(EditorContext *ctx, Engine *engine, float dt) {
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
        float rotateSpeed = 50;
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

        Vector3 moveX = cameraRight * move.x;
        Vector3 moveZ = cameraFwd * move.z;
        move = moveX + moveZ;
        move = Vector3Normalize(move);
        move.x *= xMoveSpeed;
        move.z *= zMoveSpeed;

        Vector2 rotateV2 = Vector2Scale(GetMouseDelta(), rotateSpeed);
        Vector2 rotate = {-rotateV2.x, -rotateV2.y};

        mainCamera->Move(move * dt);
        mainCamera->Rotate(rotate * dt);
    }
}

static void ProcessShaderReload(EditorContext *ctx, Engine *engine) {
    if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_R)) {
        engine->Shader_ReloadAll();
    }
}

// Process shortcuts
void ShortcutController::Process(Engine *engine, float dt) {
    ProcessDebugCamera(ctx, engine, dt);
    ProcessShaderReload(ctx, engine);
}