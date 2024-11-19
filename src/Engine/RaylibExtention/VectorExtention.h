#ifndef ENGINE_RAYLIBEXTENTION_VECTOREXTENTION_H__
#define ENGINE_RAYLIBEXTENTION_VECTOREXTENTION_H__

#include <raylib.h>
#include <raymath.h>

// Vector3 + Vector3
Vector3 operator+(const Vector3 &a, const Vector3 &b);

// Vector3 += Vector3
Vector3 operator+=(Vector3 &a, const Vector3 &b);

// Vector3 - Vector3
Vector3 operator-(const Vector3 &a, const Vector3 &b);

// Vector3 -= Vector3
Vector3 operator-=(Vector3 &a, const Vector3 &b);

// Vector3 * float
Vector3 operator*(const Vector3 &a, const float &b);

// Vector3 *= float
Vector3 operator*=(Vector3 &a, const float &b);

// Vector2 + Vector2
Vector2 operator+(const Vector2 &a, const Vector2 &b);

// Vector2 += Vector2
Vector2 operator+=(Vector2 &a, const Vector2 &b);

// Vector2 - Vector2
Vector2 operator-(const Vector2 &a, const Vector2 &b);

// Vector2 -= Vector2
Vector2 operator-=(Vector2 &a, const Vector2 &b);

// Vector2 * float
Vector2 operator*(const Vector2 &a, const float &b);

// Vector2 *= float
Vector2 operator*=(Vector2 &a, const float &b);

#endif // ENGINE_RAYLIBEXTENTION_VECTOREXTENTION_H__