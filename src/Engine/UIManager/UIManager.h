#ifndef ENGINE_UIMANAGER_UIMANAGER_H__
#define ENGINE_UIMANAGER_UIMANAGER_H__

#include "UIManagerContext.h"

class UIManager {
private:
    UIManagerContext* ctx;

public:
    UIManager();
    ~UIManager();
    void ProcessAndRender();
};

#endif // ENGINE_UIMANAGER_UIMANAGER_H__