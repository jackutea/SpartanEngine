#include "RenderPipelineContext.h"

RenderPipelineContext::RenderPipelineContext() {
    sky = new RPSkyModel();
}

RenderPipelineContext::~RenderPipelineContext() {
    delete sky;
}