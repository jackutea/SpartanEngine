#pragma once

#include "import.h"
#include "RenderPipelineContext.h"

class RenderPipeline {
public:
    RenderPipelineContext *ctx;

public:
    RenderPipeline();
    ~RenderPipeline();
    void Initialize();
    void RenderAll(CameraModel& cam);

    LightRenderer* Light_Create(LightType type);
    LightRenderer* GetMainLight();
    void Sky_SetSolidColor(Color color);
    void Model_Add(ModelAsset *model);
    
protected:
    void Sky_Render(CameraModel& cam) const;
    void Model_Render(CameraModel& cam);
};