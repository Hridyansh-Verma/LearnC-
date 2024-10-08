#pragma once
#include <iostream>

class BaseChar
{
private:
    BaseChar* ch; // Raw pointer to manage character array

public:
    // Constructors
    BaseChar(const char* s = nullptr);    // Parameterized constructor (with default null value)
    BaseChar(const BaseChar& other);        // Copy constructor
    BaseChar(BaseChar&& other) noexcept;    // Move constructor

    // Assignment Operators
    BaseChar& operator=(const BaseChar& other); // Copy assignment operator
    BaseChar& operator=(BaseChar&& other) noexcept; // Move assignment operator

    // Destructor
    ~BaseChar();

    // Utility functions
    void print() const;
};
