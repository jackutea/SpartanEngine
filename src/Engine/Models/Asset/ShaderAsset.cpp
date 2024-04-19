#include "ShaderAsset.h"

ShaderAsset::ShaderAsset() {
}

ShaderAsset::~ShaderAsset() {
    if (shader.id != 0) {
        UnloadShader(shader);
    }
}

unsigned int ShaderAsset::GetID() {
    return shader.id;
}

void ShaderAsset::Load(const char *vsPath, const char *fsPath) {
    shader = LoadShader(vsPath, fsPath);
}