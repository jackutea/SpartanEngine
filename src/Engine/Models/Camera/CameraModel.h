#pragma once

#include "../import.h"

class CameraModel {
public:
    int id;
    CameraType type;
    Camera3D cam3D;
    Camera2D cam2D;

public:
    CameraModel();
    ~CameraModel();
    void Initialize();
    void Move(Vector3 offset);
    void MoveTo(Vector3 target);
    void Rotate(Vector3 offset);
    void RotateFaceTo(Vector3 target);
    void ZoomFOV(float offset);
    void ZoomFOVTo(float target);
    void Push(float offset);
    void PushDistanceTo(float target);
    void Begin();
    void End();
};