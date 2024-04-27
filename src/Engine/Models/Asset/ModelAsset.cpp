#include "ModelAsset.h"
#include <iostream>

ModelAsset::ModelAsset() {
    renderTF = Transform();
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
    if (model.meshCount == 0) {
        throw SPT_EXCEPTION("ModelAsset::Load: model.meshCount == 0");
        return;
    }
}

void ModelAsset::Draw() {
    float angle;
    Vector3 axis;
    QuaternionToAxisAngle(renderTF.rotation, &axis, &angle);
    DrawModelEx(model, renderTF.translation, axis, angle, renderTF.scale, WHITE);
    // DrawCircle3D({0, 0, 0}, 1, {0, 1, 0}, 0, WHITE);
    // DrawModel(model, tf.translation, tf.scale.x, WHITE);
}

void ModelAsset::SetTexture(int matIndex, int texIndex, Texture2D texture) {
    if (model.materialCount <= matIndex) {
        throw SPT_EXCEPTION("ModelAsset::SetTexture: matIndex out of range");
        return;
    }
    model.materials[matIndex].maps[texIndex].texture = texture;
}

void ModelAsset::SetShader(int matIndex, Shader shader) {
    if (model.materialCount <= matIndex) {
        throw SPT_EXCEPTION("ModelAsset::SetShader: matIndex out of range");
        return;
    }
    model.materials[matIndex].shader = shader;
}

void ModelAsset::Log() {
    std::cout << "ModelAsset: " << id << std::endl;
    std::cout << "  tf: " << std::endl;
    std::cout << "    translation: " << renderTF.translation.x << ", " << renderTF.translation.y << ", " << renderTF.translation.z << std::endl;
    std::cout << "    rotation: " << renderTF.rotation.x << ", " << renderTF.rotation.y << ", " << renderTF.rotation.z << ", " << renderTF.rotation.w << std::endl;
    std::cout << "    scale: " << renderTF.scale.x << std::endl;
    std::cout << "  model: " << std::endl;
    std::cout << "    meshCount: " << model.meshCount << std::endl;
    std::cout << "    materialCount: " << model.materialCount << std::endl;
    std::cout << "    shader: " << model.materials[0].shader.id << std::endl;
}