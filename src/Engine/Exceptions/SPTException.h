#ifndef SPT_EXCEPTION_H__
#define SPT_EXCEPTION_H__

#include <iostream>

// concat file and line to SPT_EXCEPTION
#define SPT_EXCEPTION(msg) SPTException(TextFormat("%s(%s)%s",__FILE__,__LINE__,msg));

class SPTException {
public:
    const char* message;

public:
    SPTException(const char* message);
    ~SPTException();
    void What() const;
};

#endif // SPT_EXCEPTION_H__