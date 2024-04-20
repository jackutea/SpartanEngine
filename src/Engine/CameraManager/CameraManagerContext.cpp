#include "CameraManagerContext.h"

CameraManagerContext::CameraManagerContext() {

    CameraModel *defaultCamera = new CameraModel();
    defaultCamera->id = cameraIDRecord++;

    cameras = new unordered_map<int, CameraModel *>();
    cameras->insert({defaultCamera->id, defaultCamera});

    mainCameraID = defaultCamera->id;
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