#pragma once

#include<mutex>

class Singleton
{
    static Singleton* singletonInstance;
    static std::mutex mtx;
    Singleton();
    Singleton(const Singleton& instance) = delete;
    Singleton operator=(Singleton& instance) = delete;
public:
    static Singleton* getInstance();
};

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