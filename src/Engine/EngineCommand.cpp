#include "EngineContext.h"
#include "EngineCommand.h"
#include "RenderPipeline/RenderPipeline.h"

EngineCommand::EngineCommand(void* ctxPtr) {
    this->ctxPtr = ctxPtr;
}

EngineCommand::~EngineCommand() {
    delete (EngineContext*)this->ctxPtr;
}

void EngineCommand::RP_Sky_SetSolid(Color color) {
    EngineContext* ctx = (EngineContext*)this->ctxPtr;
    ctx->rp->Sky_SetSolidColor(color);
}