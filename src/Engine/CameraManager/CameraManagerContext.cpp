#include "CameraManagerContext.h"

CameraManagerContext::CameraManagerContext() {
    cameraIDRecord = 0;
    cameras = new unordered_map<int, CameraModel *>();
    mainCameraID = 0;
}

CameraManagerContext::~CameraManagerContext() {
    for (auto it = cameras->begin(); it != cameras->end(); it++) {
        delete it->second;
    }
    delete cameras;
}

CameraModel *CameraManagerContext::GetMainCamera() {
    return cameras->at(mainCameraID);
}

void CameraManagerContext::SetMainCamera(CameraModel *camera) {
    mainCameraID = camera->id;
}