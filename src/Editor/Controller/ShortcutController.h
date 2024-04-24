#ifndef ENGINE_EDITOR_CONTROLLER_SHORTCUTCONTROLLER_H__
#define ENGINE_EDITOR_CONTROLLER_SHORTCUTCONTROLLER_H__ 

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

#endif // ENGINE_EDITOR_CONTROLLER_SHORTCUTCONTROLLER_H__