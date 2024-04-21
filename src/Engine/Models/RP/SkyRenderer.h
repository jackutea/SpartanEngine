#pragma once

#include "../import.h"

class SkyRenderer {
public:
    RPSkyType skyType;
    Color solidColor;
    Color ambientColor;

public:
    SkyRenderer();
    ~SkyRenderer();
};