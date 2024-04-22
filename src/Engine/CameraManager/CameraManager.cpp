#include "CameraManager.h"

CameraManager::CameraManager() {
    ctx = new CameraManagerContext();
}

CameraManager::~CameraManager() {
    delete ctx;
}

void CameraManager::Initialize() {
    Camera3D *cam3D = &this->CreateCamera()->cam3D;
    cam3D->position = {0.0f, 0.0f, -10.0f};
    cam3D->target = {0.0f, 0.0f, 0.0f};
}

CameraModel *CameraManager::CreateCamera() {
    CameraModel *camera = new CameraModel();
    camera->id = ctx->cameraIDRecord++;

    ctx->cameras->insert({camera->id, camera});

    if (ctx->mainCameraID == 0) {
        ctx->mainCameraID = camera->id;
    }
    return camera;
}

CameraModel *CameraManager::GetMainCamera() {
    return ctx->GetMainCamera();
}

void CameraManager::SetMainCamera(CameraModel *camera) {
    ctx->SetMainCamera(camera);
}

void CameraManager::Begin() const {
    ctx->GetMainCamera()->Begin();
}

void CameraManager::End() const {
    ctx->GetMainCamera()->End();
}