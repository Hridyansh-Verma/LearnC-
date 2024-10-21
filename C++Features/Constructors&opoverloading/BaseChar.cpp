#include "BaseChar.h"
#include <cstring> // For strlen, strcpy

// Parameterized constructor
BaseChar::BaseChar(const char* s)
{
    if (s) {
        ch = new char[strlen(s) + 1]; // Allocate memory for the string
        strcpy(ch, s);                 // Copy the string into the allocated memory
    } else {
        ch = nullptr;                  // Initialize to nullptr if input is null
    }
}

// Copy constructor
BaseChar::BaseChar(const BaseChar& other)
{
    if (other.ch) {
        ch = new char[strlen(other.ch) + 1]; // Allocate memory for the string
        strcpy(ch, other.ch);                 // Copy the string from the source object
    } else {
        ch = nullptr;                          // Initialize to nullptr if source is null
    }
}

// Move constructor
BaseChar::BaseChar(BaseChar&& other) noexcept
{
    ch = other.ch;      // Steal the pointer from the other object
    other.ch = nullptr; // Set the other pointer to nullptr
}

// Copy assignment operator
BaseChar& BaseChar::operator=(const BaseChar& other)
{
    if (this == &other) {
        return *this; // Self-assignment check
    }

    delete[] ch; // Delete existing memory

    if (other.ch) {
        ch = new char[strlen(other.ch) + 1]; // Allocate new memory for the string
        strcpy(ch, other.ch);                 // Copy the string from the source object
    } else {
        ch = nullptr;                          // Initialize to nullptr if source is null
    }

    return *this;
}

// Move assignment operator
BaseChar& BaseChar::operator=(BaseChar&& other) noexcept
{
    if (this == &other) {
        return *this; // Self-assignment check
    }

    delete[] ch; // Delete existing memory

    ch = other.ch; // Steal the pointer from the other object
    other.ch = nullptr; // Set the other pointer to nullptr

    return *this;
}

// Destructor
BaseChar::~BaseChar()
{
    delete[] ch; // Free allocated memory
}

// Utility function to print the string
void BaseChar::print() const
{
    if (ch) {
        std::cout << ch << std::endl; // Print the string
    } else {
        std::cout << "Empty" << std::endl; // Indicate that the string is empty
    }
}
