#include "VectorExtention.h"

// Vector3 + Vector3
Vector3 operator+(const Vector3 &a, const Vector3 &b) {
    return Vector3Add(a, b);
}

// Vector3 += Vector3
Vector3 operator+=(Vector3 &a, const Vector3 &b) {
    a = Vector3Add(a, b);
    return a;
}

// Vector3 - Vector3
Vector3 operator-(const Vector3 &a, const Vector3 &b) {
    return Vector3Subtract(a, b);
}

// Vector3 -= Vector3
Vector3 operator-=(Vector3 &a, const Vector3 &b) {
    a = Vector3Subtract(a, b);
    return a;
}

// Vector3 * float
Vector3 operator*(const Vector3 &a, const float &b) {
    return Vector3Scale(a, b);
}

// Vector3 *= float
Vector3 operator*=(Vector3 &a, const float &b) {
    a = Vector3Scale(a, b);
    return a;
}

// Vector2 + Vector2
Vector2 operator+(const Vector2 &a, const Vector2 &b) {
    return Vector2Add(a, b);
}

// Vector2 += Vector2
Vector2 operator+=(Vector2 &a, const Vector2 &b) {
    a = Vector2Add(a, b);
    return a;
}

// Vector2 - Vector2
Vector2 operator-(const Vector2 &a, const Vector2 &b) {
    return Vector2Subtract(a, b);
}

// Vector2 -= Vector2
Vector2 operator-=(Vector2 &a, const Vector2 &b) {
    a = Vector2Subtract(a, b);
    return a;
}

// Vector2 * float
Vector2 operator*(const Vector2 &a, const float &b) {
    return Vector2Scale(a, b);
}

// Vector2 *= float
Vector2 operator*=(Vector2 &a, const float &b) {
    a = Vector2Scale(a, b);
    return a;
}