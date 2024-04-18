#pragma once

#include "CameraManagerContext.h"

class CameraManager {
public:
    CameraManagerContext* ctx;
public:
    CameraManager();
    ~CameraManager();
    void Initialize();
    void Begin();
    void End();
};