#pragma once

#include "CameraManagerContext.h"

class CameraManager {
private:
    CameraManagerContext* ctx;

public:
    CameraManager();
    ~CameraManager();
    void Initialize();
    CameraModel *CreateCamera();
    void SetMainCamera(CameraModel* camera);
    CameraModel* GetMainCamera();
    void Begin() const;
    void End() const;
};