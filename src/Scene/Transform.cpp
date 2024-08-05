#include "Transform.h"

vec3 Atlas::Scene::Transform::xAxis = vec3(1.0f, 0.0f, 0.0f);
vec3 Atlas::Scene::Transform::yAxis = vec3(0.0f, 1.0f, 0.0f);
vec3 Atlas::Scene::Transform::zAxis = vec3(0.0f, 0.0f, 1.0f);

void Atlas::Scene::Transform::UpdateMatrix() {
    Matrix = mat4x4(1.0f);

    Matrix = translate(Matrix, this->Position);
    Matrix = scale(Matrix, this->Scale);

    Matrix = rotate(Matrix, radians(this->Rotation.x), xAxis);
    Matrix = rotate(Matrix, radians(this->Rotation.y), yAxis);
    Matrix = rotate(Matrix, radians(this->Rotation.z), zAxis);
}

void Atlas::Scene::Transform::UpdateInverseMatrix() {
    InverseMatrix = this->Matrix;
    InverseMatrix = inverse(InverseMatrix);
}

Atlas::Scene::Transform::Transform() :
    Matrix(mat4x4(1.0f)), InverseMatrix(mat4x4(1.0f)),
    Position(vec3(0.0f, 0.0f, 0.0f)), Rotation(vec3(0.0f, 0.0f, 0.0f)),
    Scale(vec3(1.0f, 1.0f, 1.0f))
{}

Atlas::Scene::Transform::Transform(vec3 t_Position) :
    Matrix(mat4x4(1.0f)), InverseMatrix(mat4x4(1.0f)),
    Position(t_Position), Rotation(vec3(0.0f, 0.0f, 0.0f)), Scale(vec3(1.0f, 1.0f, 1.0f))
{}

Atlas::Scene::Transform::Transform(vec3 t_Position, vec3 t_Rotation) :
    Matrix(mat4x4(1.0f)), InverseMatrix(mat4x4(1.0f)),
    Position(t_Position), Rotation(t_Rotation), Scale(vec3(1.0f, 1.0f, 1.0f))
{}

Atlas::Scene::Transform::Transform(vec3 t_Position, vec3 t_Rotation, vec3 t_Scale) :
    Matrix(mat4x4(1.0f)), InverseMatrix(mat4x4(1.0f)),
    Position(t_Position), Rotation(t_Rotation), Scale(t_Scale)
{}
