#include "PF_Input.h"
#include "../../../include/raymath.h"

namespace PureFunctions {
// Right-Handed 3D
Vector2 Input_GetKeyMoveAxis3D(int enumKeyUp, int enumKeyDown, int enumKeyLeft, int enumKeyRight) {
    Vector2 axis = {0, 0};
    if (IsKeyDown(enumKeyUp)) {
        axis.y = 1;
    } else if (IsKeyDown(enumKeyDown)) {
        axis.y = -1;
    }
    if (IsKeyDown(enumKeyLeft)) {
        axis.x = 1;
    } else if (IsKeyDown(enumKeyRight)) {
        axis.x = -1;
    }
    axis = Vector2Normalize(axis);
    return axis;
}

// Screen 2D
Vector2 Input_GetKeyMoveAxis2D(int enumKeyUp, int enumKeyDown, int enumKeyLeft, int enumKeyRight) {
    Vector2 axis = {0, 0};
    if (IsKeyDown(enumKeyUp)) {
        axis.y = 1;
    } else if (IsKeyDown(enumKeyDown)) {
        axis.y = -1;
    }
    if (IsKeyDown(enumKeyLeft)) {
        axis.x = -1;
    } else if (IsKeyDown(enumKeyRight)) {
        axis.x = 1;
    }
    axis = Vector2Normalize(axis);
    return axis;
}
}