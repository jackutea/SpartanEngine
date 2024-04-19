#pragma once

#include "CameraManagerContext.h"

class CameraManager {
public:
    CameraManagerContext* ctx;

public:
    CameraManager();
    ~CameraManager();
    void Initialize();
    CameraModel& GetMainCamera() const;
    void Begin() const;
    void End() const;
};