#ifndef SPT_EXCEPTION_H__
#define SPT_EXCEPTION_H__

#include <iostream>

class SPTException {
public:
    const char* message;

public:
    SPTException(const char* message);
    ~SPTException();
    void What() const;
};

#endif // SPT_EXCEPTION_H__