#ifndef ENGINE_CAMERAMANAGER_CAMERAMANAGERCONTEXT_H__
#define ENGINE_CAMERAMANAGER_CAMERAMANAGERCONTEXT_H__

#include "import.h"
#include <unordered_map>
using namespace std;

class CameraManagerContext {
public:
    int mainCameraID;
    int cameraIDRecord;
    unordered_map<int, CameraModel *> *cameras;

public:
    CameraManagerContext();
    ~CameraManagerContext();
    CameraModel* GetMainCamera();
    void SetMainCamera(CameraModel* camera);
};

#endif // ENGINE_CAMERAMANAGER_CAMERAMANAGERCONTEXT_H__