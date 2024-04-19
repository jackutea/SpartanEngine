#include "ModelAsset.h"

ModelAsset::ModelAsset() {
}

ModelAsset::~ModelAsset() {
    if (model.meshes != nullptr) {
        UnloadModel(model);
    }
}

unsigned int ModelAsset::GetID() {
    return id;
}

void ModelAsset::Load(const char *path) {
    model = LoadModel(path);
}

void ModelAsset::Draw() {
    float angle;
    Vector3 axis;
    QuaternionToAxisAngle(tf.rotation, &axis, &angle);
    DrawModelEx(model, tf.translation, axis, angle, tf.scale, WHITE);
}

void ModelAsset::SetTexture(int matIndex, int texIndex, Texture2D texture) {
    model.materials[matIndex].maps[texIndex].texture = texture;
}

void ModelAsset::SetShader(int matIndex, Shader shader) {
    model.materials[matIndex].shader = shader;
}