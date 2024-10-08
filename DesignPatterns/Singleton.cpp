#include "Singleton.h"
#include<iostream>
#include<mutex>

// Only one instance
// Global access
// No ownership
// Lazy initialisation

Singleton* Singleton::singletonInstance=nullptr;
std::mutex Singleton::mtx;

Singleton::Singleton()
{
    std::cout << "Singleton Object Instantiated" << std::endl;
}

Singleton * Singleton::getInstance()
{
    if(singletonInstance==nullptr)
    {
        mtx.lock();
        if(singletonInstance==nullptr)
        {
            singletonInstance = new Singleton();
        }
        mtx.unlock();
    }
    return singletonInstance;
}