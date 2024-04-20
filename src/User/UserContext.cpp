#include "UserContext.h"

UserContext::UserContext() {
}

UserContext::~UserContext() {
    if (model != nullptr) {
        delete model;
    }

    if (tex != nullptr) {
        delete tex;
    }

    if (sha != nullptr) {
        delete sha;
    }
}