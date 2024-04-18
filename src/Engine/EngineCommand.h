#pragma once

#include "EngineContext.h"

class EngineCommand {
private:
    EngineContext* ctx;

public:
    EngineCommand(EngineContext* ctx) {
        this->ctx = ctx;
    }

    void RP_Sky_SetSolid(Color color) {
        ctx->rp->Sky_SetSolidColor(color);
    }
};