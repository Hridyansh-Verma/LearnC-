#pragma
class Base
{
    int *m_ptr;

    // 1 Parameterised Constructor
    // 2 Copy Constructor
    // 3 Move Constructor
    // 4 Copy Assignment Operator
    // 5 Move Assignment Operator
    // 6 Destructor
    // 7 + Operator
    // 8 ++ preincrement operator
    // 9 ++ post increment operator

public:
    Base(int x=0);
    Base(const Base &other);
    Base(Base &&other);
    Base& operator=(const Base &other);
    Base& operator=(Base&& other);
    ~Base();
    Base operator+ (const Base &other);
    Base& operator++();
    Base operator++(int);
};