#include "LightRenderer.h"

LightRenderer::LightRenderer() {
}

LightRenderer::~LightRenderer() {
}

void LightRenderer::SetupShader(Shader shader) {
    int i = index;
    enabledLoc = GetShaderLocation(shader, TextFormat("lights[%i].enabled", i));
    typeLoc = GetShaderLocation(shader, TextFormat("lights[%i].type", i));
    positionLoc = GetShaderLocation(shader, TextFormat("lights[%i].position", i));
    targetLoc = GetShaderLocation(shader, TextFormat("lights[%i].target", i));
    colorLoc = GetShaderLocation(shader, TextFormat("lights[%i].color", i));
    attenuationLoc = GetShaderLocation(shader, TextFormat("lights[%i].attenuation", i));
}

void LightRenderer::UpdateShader(Shader shader) {
    SetShaderValue(shader, enabledLoc, &isEnable, SHADER_UNIFORM_INT);

    int ftype = (int)type;
    SetShaderValue(shader, typeLoc, &ftype, SHADER_UNIFORM_INT);

    float fpos[3] = {pos.x, pos.y, pos.z};
    SetShaderValue(shader, positionLoc, &fpos, SHADER_UNIFORM_VEC3);

    float ftarget[3] = {target.x, target.y, target.z};
    SetShaderValue(shader, targetLoc, &ftarget, SHADER_UNIFORM_VEC3);

    float fcolor[4] = {(float)color.r / (float)255, (float)color.g / (float)255, (float)color.b / (float)255, (float)color.a / (float)255};
    SetShaderValue(shader, colorLoc, &fcolor, SHADER_UNIFORM_VEC4);

    SetShaderValue(shader, attenuationLoc, &attenuation, SHADER_UNIFORM_FLOAT);
}