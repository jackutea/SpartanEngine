#pragma once

#include "../../include/raylib.h"

class EngineCommand {
private:
    void* ctxPtr;

public:
    EngineCommand(void* ctx);
    ~EngineCommand();

    void RP_Sky_SetSolid(Color color);
};