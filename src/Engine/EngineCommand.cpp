#include "EngineContext.h"
#include "EngineCommand.h"
#include "RenderPipeline/RenderPipeline.h"

EngineCommand::EngineCommand(EngineContext* ctx) {
    this->ctx = ctx;
}

EngineCommand::~EngineCommand() {
    delete ctx;
}

CameraModel& EngineCommand::GetMainCamera() const {
    return ctx->cameraManager->GetMainCamera();
}

void EngineCommand::RP_Sky_SetSolid(Color color) {
    ctx->rp->Sky_SetSolidColor(color);
}