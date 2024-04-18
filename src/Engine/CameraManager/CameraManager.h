#pragma once

#include "import.h"

class CameraManager {
public:
    CameraType type;
    Camera3D *cam3D;
    Camera2D *cam2D;

public:
    CameraManager();
    ~CameraManager();
    void Initialize();
    void Begin();
    void End();
};