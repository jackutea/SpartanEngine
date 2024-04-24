#ifndef ENGINE_EDITOR_EDITORCONTEXT_H__
#define ENGINE_EDITOR_EDITORCONTEXT_H__

class EditorContext {
public:
    bool isDebugCameraEnabled;
    float debugCameraSpeedMultiply;

public:
    EditorContext();
    ~EditorContext();
};

#endif // ENGINE_EDITOR_EDITORCONTEXT_H__