#pragma once

#include "import.h"

class CameraManagerContext {
public:
    CameraType type;
    Camera3D *cam3D;
    Camera2D *cam2D;

public:
    CameraManagerContext();
    ~CameraManagerContext();
};