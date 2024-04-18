#pragma once

#include "import.h"
#include "RenderPipelineContext.h"

class RenderPipeline {
public:
    RenderPipelineContext *ctx;

public:
    RenderPipeline();
    void Sky_Render();
    void Sky_SetSolidColor(Color color);
};