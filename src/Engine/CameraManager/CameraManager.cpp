#include "CameraManager.h"

CameraManager::CameraManager() {
    type = CameraType::Camera3D;
    cam3D = new Camera3D();
    cam2D = new Camera2D();
}

CameraManager::~CameraManager() {
    delete cam3D;
    delete cam2D;
}

void CameraManager::Initialize() {
    cam3D->position = { 0.0f, 0.0f, -200.0f };
    cam3D->target = { 0.0f, 0.0f, 0.0f };
    cam3D->up = { 0.0f, 1.0f, 0.0f };
    cam3D->fovy = 45.0f;
    cam3D->projection = CAMERA_PERSPECTIVE;

    cam2D->offset = { 0.0f, 0.0f };
    cam2D->target = { 0.0f, 0.0f };
    cam2D->rotation = 0.0f;
    cam2D->zoom = 1.0f;
}

void CameraManager::Begin() {
    if (type == CameraType::Camera3D) {
        BeginMode3D(*cam3D);
    } else {
        BeginMode2D(*cam2D);
    }
}

void CameraManager::End() {
    if (type == CameraType::Camera3D) {
        EndMode3D();
    } else {
        EndMode2D();
    }
}