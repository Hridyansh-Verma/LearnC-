#include<stdio.h>
#include<thread>
#include "DesignPatterns/Singleton.h"
#include "DesignPatterns/CreateInstance.h"

int main()
{
    std::thread t1(create::createSingletonInstance);
    std::thread t2(create::createSingletonInstance);
    std::thread t3(create::createSingletonInstance);
    t1.join();
    t2.join();
    t3.join();
}