#ifndef ENGINE_RENDERPIPELINE_RENDERPIPELINE_H__
#define ENGINE_RENDERPIPELINE_RENDERPIPELINE_H__

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
    SkyRenderer* GetSky();
    void Sky_SetAsSolidColor(Color color);
    void Model_Add(ModelAsset *model);
    
protected:
    void Sky_Render(CameraModel& cam) const;
    void Model_Render(CameraModel& cam);
};

#endif // ENGINE_RENDERPIPELINE_RENDERPIPELINE_H__