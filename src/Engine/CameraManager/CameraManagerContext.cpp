#include "CameraManagerContext.h"

CameraManagerContext::CameraManagerContext() {
    type = CameraType::Camera3D;
    cam3D = new Camera3D();
    cam2D = new Camera2D();
}

CameraManagerContext::~CameraManagerContext() {
    delete cam3D;
    delete cam2D;
}