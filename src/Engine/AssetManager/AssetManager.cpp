#include "AssetManager.h"

AssetManager::AssetManager() {
    ctx = new AssetManagerContext();
}

AssetManager::~AssetManager() {
    delete ctx;
}