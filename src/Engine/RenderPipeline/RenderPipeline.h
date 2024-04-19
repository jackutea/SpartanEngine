#pragma once

#include "import.h"
#include "RenderPipelineContext.h"

class RenderPipeline {
public:
    RenderPipelineContext *ctx;

public:
    RenderPipeline();
    ~RenderPipeline();
    void Sky_Render() const;
    void Sky_SetSolidColor(Color color);
};