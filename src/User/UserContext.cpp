#include "UserContext.h"

UserContext::UserContext() {
}

UserContext::~UserContext() {
    if (tex != nullptr) {
        delete tex;
    }
    if (sha != nullptr) {
        delete sha;
    }
    if (model != nullptr) {
        delete model;
    }
}