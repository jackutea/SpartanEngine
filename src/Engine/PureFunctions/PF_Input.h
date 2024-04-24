#ifndef ENGINE_PUREFUNCTIONS_PF_INPUT_H__
#define ENGINE_PUREFUNCTIONS_PF_INPUT_H__

#include "../../../include/raylib.h"

namespace PureFunctions {
Vector2 Input_GetKeyMoveAxis3D(int enumKeyUp, int enumKeyDown, int enumKeyLeft, int enumKeyRight);
Vector2 Input_GetKeyMoveAxis2D(int enumKeyUp, int enumKeyDown, int enumKeyLeft, int enumKeyRight);
}

#endif // ENGINE_PUREFUNCTIONS_PF_INPUT_H__