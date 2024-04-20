#include "CameraModel.h"

CameraModel::CameraModel() {
    type = CameraType::Camera3D;
    
    cam3D = {0};
    cam3D.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    cam3D.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    cam3D.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    cam3D.fovy = 45.0f;
    cam3D.projection = CAMERA_PERSPECTIVE;

    cam2D = {0};
    cam2D.offset = (Vector2){ 0.0f, 0.0f };
    cam2D.target = (Vector2){ 0.0f, 0.0f };
    cam2D.rotation = 0.0f;
    cam2D.zoom = 1.0f;

}

CameraModel::~CameraModel() {
}

void CameraModel::Initialize() {
}

void CameraModel::Move(Vector3 offset) {
    if (type == CameraType::Camera3D) {
        cam3D.target = Vector3Add(cam3D.target, offset);
    } else if (type == CameraType::Camera2D) {
        cam2D.offset = Vector2Add(cam2D.offset, (Vector2){offset.x, offset.y});
    }
}

void CameraModel::MoveTo(Vector3 target) {
    if (type == CameraType::Camera3D) {
        cam3D.target = target;
    } else if (type == CameraType::Camera2D) {
        cam2D.offset = (Vector2){target.x, target.y};
    }
}

void CameraModel::Rotate(Vector3 offset) {
    if (type == CameraType::Camera3D) {
        cam3D.target = Vector3Add(cam3D.target, offset);
    } else if (type == CameraType::Camera2D) {
        cam2D.target = Vector2Add(cam2D.target, (Vector2){offset.x, offset.y});
    }
}

void CameraModel::RotateFaceTo(Vector3 target) {
    if (type == CameraType::Camera3D) {
        cam3D.target = target;
    } else if (type == CameraType::Camera2D) {
        cam2D.target = (Vector2){target.x, target.y};
    }
}

void CameraModel::ZoomFOV(float offset) {
    if (type == CameraType::Camera3D) {
        cam3D.fovy += offset;
    } else if (type == CameraType::Camera2D) {
        cam2D.zoom += offset;
    }
}

void CameraModel::ZoomFOVTo(float target) {
    if (type == CameraType::Camera3D) {
        cam3D.fovy = target;
    } else if (type == CameraType::Camera2D) {
        cam2D.zoom = target;
    }
}

void CameraModel::Push(float offset) {
    if (type == CameraType::Camera3D) {
        cam3D.position.z += offset;
    } else if (type == CameraType::Camera2D) {
        // Can't push in 2D
    }
}

void CameraModel::PushDistanceTo(float target) {
    if (type == CameraType::Camera3D) {
        cam3D.position.y = target;
    } else if (type == CameraType::Camera2D) {
        cam2D.offset.y = target;
    }
}

void CameraModel::Begin() {
    if (type == CameraType::Camera3D) {
        BeginMode3D(cam3D);
    } else if (type == CameraType::Camera2D) {
        BeginMode2D(cam2D);
    }
}

void CameraModel::End() {
    if (type == CameraType::Camera3D) {
        EndMode3D();
    } else if (type == CameraType::Camera2D) {
        EndMode2D();
    }
}