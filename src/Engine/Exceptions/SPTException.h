#pragma once

#include <iostream>

class SPTException {
public:
    const char* message;

public:
    SPTException(const char* message);
    ~SPTException();
    void What() const;
};