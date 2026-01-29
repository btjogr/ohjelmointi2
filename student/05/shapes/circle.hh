#ifndef CIRCLE_HH
#define CIRCLE_HH
#include <iostream>
#include "shape.hh"

const double PI = 3.14159;

class Circle : public Shape
{
public:
    Circle(char color, double radius);

    virtual ~Circle();

    virtual double area();

    virtual double circumference();

    virtual void print(int running_number);

private:

    char color_;
    double radius_;
};

#endif // CIRCLE_HH
