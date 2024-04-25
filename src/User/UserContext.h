#pragma once

#include "../Engine/export_for_user.h"

class UserContext {
public:
    ModelAsset* model;
    ModelAsset* model2;
    TextureAsset* tex;
    TextureAsset* tex2;
    ShaderAsset* sha;
    ShaderAsset* sha2;

public:
    UserContext();
    ~UserContext();
};