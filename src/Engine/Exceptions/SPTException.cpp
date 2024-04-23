#include "SPTException.h"

SPTException::SPTException(const char* message) {
    this->message = message;
}

SPTException::~SPTException() {
}

void SPTException::What() const {
    std::cout << "SPTException: " << message << std::endl;
}