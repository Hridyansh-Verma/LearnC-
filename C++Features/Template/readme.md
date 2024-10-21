Assignment 1

Convert the following functions into templates

int Add(int x,int y) ; //Return the sum of two elements
int ArraySum(const int *pArr, size_t arrSize); //Returns the sum of array elements
int Max(const int *pArr, size_t arrSize) ; //Return the largest element in the array
std::pair<int,int> MinMax(const int *pArr, size_t arrSize) ; //Return the smallest and largest element in a pair
Take care to avoid copies of user-defined objects wherever applicable.

Template Argument Deduction and Instantiation

A template func or class acts only as a blueprint
Compiler generates code from blueprint at compile time
Known as template instantiation
Occurse implicitly when
    a func template is invoked
    taking address of a func template e.g int(*func)(int,int)
    using explicit instantiation
    creating explicit specialisation
full def of template in header

