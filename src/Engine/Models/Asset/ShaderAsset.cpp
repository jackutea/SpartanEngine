#include "ShaderAsset.h"
#include "string.h"
#include <iostream>

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

const char *ShaderAsset::GetName() {
    return name;
}

void ShaderAsset::Load(const char *name, const char *vsPath, const char *fsPath) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    shader = LoadShader(vsPath, fsPath);
}

void ShaderAsset::InitLocs(int lightIndex) {
    lit_enabledLoc = GetShaderLocation(shader, TextFormat("lights[%i].enabled", lightIndex));
    lit_typeLoc = GetShaderLocation(shader, TextFormat("lights[%i].type", lightIndex));
    lit_positionLoc = GetShaderLocation(shader, TextFormat("lights[%i].position", lightIndex));
    lit_targetLoc = GetShaderLocation(shader, TextFormat("lights[%i].target", lightIndex));
    lit_colorLoc = GetShaderLocation(shader, TextFormat("lights[%i].color", lightIndex));
    lit_attenuationLoc = GetShaderLocation(shader, TextFormat("lights[%i].attenuation", lightIndex));
    lit_countLoc = GetShaderLocation(shader, "lightsCount");
    viewPosLoc = GetShaderLocation(shader, "viewPos");
    ambientLoc = GetShaderLocation(shader, "ambient");
}

void ShaderAsset::SetValue(int locIndex, void *value, int uniformType) {
    SetShaderValue(shader, locIndex, value, uniformType);
}