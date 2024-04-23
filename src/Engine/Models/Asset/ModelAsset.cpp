#include "ModelAsset.h"
#include <iostream>

ModelAsset::ModelAsset() {
    tf = Transform();
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
    // DrawCircle3D({0, 0, 0}, 1, {0, 1, 0}, 0, WHITE);
    // DrawModel(model, tf.translation, tf.scale.x, WHITE);
}

void ModelAsset::SetTexture(int matIndex, int texIndex, Texture2D texture) {
    model.materials[matIndex].maps[texIndex].texture = texture;
}

void ModelAsset::SetShader(int matIndex, Shader shader) {
    model.materials[matIndex].shader = shader;
}

void ModelAsset::Log() {
    std::cout << "ModelAsset: " << id << std::endl;
    std::cout << "  tf: " << std::endl;
    std::cout << "    translation: " << tf.translation.x << ", " << tf.translation.y << ", " << tf.translation.z << std::endl;
    std::cout << "    rotation: " << tf.rotation.x << ", " << tf.rotation.y << ", " << tf.rotation.z << ", " << tf.rotation.w << std::endl;
    std::cout << "    scale: " << tf.scale.x << std::endl;
    std::cout << "  model: " << std::endl;
    std::cout << "    meshCount: " << model.meshCount << std::endl;
    std::cout << "    materialCount: " << model.materialCount << std::endl;
    std::cout << "    shader: " << model.materials[0].shader.id << std::endl;
}