#pragma once

#include "../EditorContext.h"
#include "../import.h"

class ShortcutController {
private:
    EditorContext *ctx;

public:
    ShortcutController();
    ~ShortcutController();
    void Inject(EditorContext *ctx);
    void Process(Engine *engine, float dt);
};