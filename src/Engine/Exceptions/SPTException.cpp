#include "SPTException.h"

SPTException::SPTException(const char* message) {
    this->message = message;
}

SPTException::~SPTException() {
}

void SPTException::What() const {
    std::cout << __FILE__ << "()" << __LINE__ << ") SPTException: " << message << std::endl;
}