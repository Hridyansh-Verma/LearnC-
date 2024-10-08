#include<iostream>
#include "Base.h"

Base::Base(int x) : m_ptr(new int(x)) 
{
    std::cout << "Parameterised constructor called" << std::endl;
}

Base::Base(const Base &other) : m_ptr(other.m_ptr? new int (*other.m_ptr):nullptr)
{
    std::cout << "Copy constructor called" << std::endl;
}

Base::Base(Base &&other) : m_ptr(other.m_ptr)
{
    other.m_ptr = nullptr;
    std::cout << "Move constructor called" << std::endl;
}

Base &Base::operator=(const Base &other)
{
    if(this!=&other)
    {
        delete m_ptr;
        m_ptr = other.m_ptr ? new int(*other.m_ptr) : nullptr;
    }
    std::cout << "Assignment operator called" << std::endl;
    return *this;
}

Base &Base::operator=(Base &&other)
{
    if(this != &other)
    {
        delete m_ptr;
        m_ptr=other.m_ptr;
        other.m_ptr=nullptr;
    }
    std::cout << "Move Assignment operator called" << std::endl;
    return *this;
}

Base::~Base()
{
    delete m_ptr;
    m_ptr=nullptr;
}

Base Base::operator+(const Base &other)
{
    return Base((m_ptr?*m_ptr:0)+(other.m_ptr?*other.m_ptr:0));
}

Base &Base::operator++()
{
    if(m_ptr)
    {
        (*m_ptr)++;
    }
    return *this;
}

Base Base::operator++(int)
{
    Base help(*this);
    (*m_ptr)++;
    return help;
}
