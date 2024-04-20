#include "CameraManager.h"

CameraManager::CameraManager() {
    ctx = new CameraManagerContext();
}

CameraManager::~CameraManager() {
    delete ctx;
}

void CameraManager::Initialize() {
    Camera3D *cam3D = &ctx->GetMainCamera()->cam3D;
    cam3D->position = {0.0f, 0.0f, -200.0f};
}

CameraModel *CameraManager::GetMainCamera() {
    return ctx->GetMainCamera();
}

void CameraManager::Begin() const {
    ctx->GetMainCamera()->Begin();
}

void CameraManager::End() const {
    ctx->GetMainCamera()->End();
}