#include "Shape.h"

// Circle class constructor
Circle::Circle(double radius) : radius(radius)
{
    cout << "Call Circle class constructor" << endl;
}

// Circle class destructor
Circle::~Circle()
{
    cout << "Call Circle class destructor" << endl;
}
생

    double
    Circle::getArea()
{
    return (radius * radius * 3.1415);
}

void Circle::print()
{
    cout << "Circle's radius : " << radius << endl;
}

// Square class constructor
Square::Square(double side) : side(side)
{
    cout << "Call Square class constructor" << endl;
}

// Square class destructor
Square::~Square()
{
    cout << "Call Square class destructor" << endl;
}

double Square::getArea()
{
    return (side * side);
}

void Square::print()
{
    cout << "Square's side : " << side << endl;
}

// Rect class constructor
Rect::Rect(double width, double height) : width(width), height(height)
{
    cout << "Call Rect class constructor" << endl;
}

// Rect class destructor
Rect::~Rect()
{
    cout << "Call Rect class destructor" << endl;
}

double Rect::getArea()
{
    return (width * height);
}

void Rect::print()
{
    cout << "Rect's width : " << width << ", height : " << height << endl;
}