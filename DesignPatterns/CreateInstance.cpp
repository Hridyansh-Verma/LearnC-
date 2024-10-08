// CreateInstance.cpp
#include "CreateInstance.h"  // Include the header

namespace create {
    Singleton* createSingletonInstance() {
        return Singleton::getInstance();
    }
}
