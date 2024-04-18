#include "CameraManager.h"

CameraManager::CameraManager() {
    ctx = new CameraManagerContext();
}

CameraManager::~CameraManager() {
    delete ctx;
}

void CameraManager::Initialize() {
    Camera3D *cam3D = ctx->cam3D;
    cam3D->position = {0.0f, 0.0f, -200.0f};
    cam3D->target = {0.0f, 0.0f, 0.0f};
    cam3D->up = {0.0f, 1.0f, 0.0f};
    cam3D->fovy = 45.0f;
    cam3D->projection = CAMERA_PERSPECTIVE;

    Camera2D *cam2D = ctx->cam2D;
    cam2D->offset = {0.0f, 0.0f};
    cam2D->target = {0.0f, 0.0f};
    cam2D->rotation = 0.0f;
    cam2D->zoom = 1.0f;
}

void CameraManager::Begin() {
    CameraType type = ctx->type;
    if (type == CameraType::Camera3D) {
        Camera3D *cam3D = ctx->cam3D;
        BeginMode3D(*cam3D);
    } else {
        Camera2D *cam2D = ctx->cam2D;
        BeginMode2D(*cam2D);
    }
}

void CameraManager::End() {
    CameraType type = ctx->type;
    if (type == CameraType::Camera3D) {
        EndMode3D();
    } else {
        EndMode2D();
    }
}