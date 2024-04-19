#pragma once

#include "EngineContext.h"

class EngineCommand {
private:
    EngineContext* ctx;

public:
    EngineCommand(EngineContext* ctx);
    ~EngineCommand();

    // ==== Camera ====
    CameraModel& GetMainCamera() const;

    // ==== RP ====
    void RP_Sky_SetSolid(Color color);
};