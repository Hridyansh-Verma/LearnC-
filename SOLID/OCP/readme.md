The Open/Closed Principle (OCP) states that:

Software entities (like classes, modules, and functions) should be open for extension but closed for modification.
This means that you should be able to add new functionality to a system without altering existing code, thus avoiding unintended side effects or bugs in already tested code.

class Shape
{
    string shape;
    int radius;
    int height,width;
    int getArea()
    {
        if(shape=="circle")
        {
            return pi*radius*radius;
        }
        else if(shape=="rectangle")
        {
            return height*width;
        }
    }
};

closed for extending . Now introducing new shape Triangle you will have to modify the Shape code. Instead use Shape interface and extend them in to your new Shape class like follows

class Shape
{
public:
    virtual int getArea()=0;
};

class Triangle : public Shape
{

};