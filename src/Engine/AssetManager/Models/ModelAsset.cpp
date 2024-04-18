#include "ModelAsset.h"

ModelAsset::ModelAsset() {
}

ModelAsset::~ModelAsset() {
    if (model.meshes != nullptr) {
        UnloadModel(model);
    }
}

void ModelAsset::Load(const char *path) {
    model = LoadModel(path);
}

void ModelAsset::Draw(Vector3 pos, Vector3 rotateAxis, float angle, Vector3 scale) {
    DrawModelEx(model, pos, rotateAxis, angle, scale, WHITE);
}

void ModelAsset::SetTexture(int matIndex, int texIndex, Texture2D texture) {
    model.materials[matIndex].maps[texIndex].texture = texture;
}

void ModelAsset::SetShader(int matIndex, Shader shader) {
    model.materials[matIndex].shader = shader;
}