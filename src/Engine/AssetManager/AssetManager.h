#pragma once

#include "import.h"
#include "AssetManagerContext.h"

class AssetManager {
public:
    AssetManagerContext *ctx;

public:
    AssetManager();
    ~AssetManager();
};