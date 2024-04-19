#pragma once

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
    CameraModel& GetMainCamera() const;
};