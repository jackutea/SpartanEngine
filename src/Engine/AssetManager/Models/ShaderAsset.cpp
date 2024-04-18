#include "ShaderAsset.h"

ShaderAsset::ShaderAsset() {
    id = 0;
}

ShaderAsset::~ShaderAsset() {
    if (shader.id != 0) {
        UnloadShader(shader);
    }
}

void ShaderAsset::Load(const char *vsPath, const char *fsPath) {
    shader = LoadShader(vsPath, fsPath);
}