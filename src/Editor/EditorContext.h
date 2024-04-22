#pragma once

class EditorContext {
public:
    bool isDebugCameraEnabled;
    float debugCameraSpeedMultiply;

public:
    EditorContext();
    ~EditorContext();
};