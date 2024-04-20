#pragma once

#include "../Engine/export_for_user.h"

class UserContext {
public:
    ModelAsset* model;
    TextureAsset* tex;
    ShaderAsset* sha;

public:
    UserContext();
    ~UserContext();
};