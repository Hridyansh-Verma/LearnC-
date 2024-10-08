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