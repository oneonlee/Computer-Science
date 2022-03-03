#pragma once

#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double getArea() = 0;
    virtual void print() = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double);
    ~Circle();
    virtual double getArea();
    virtual void print();
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double);
    ~Square();
    virtual double getArea();
    virtual void print();
};

class Rect : public Shape
{
private:
    double width;
    double height;

public:
    Rect(double, double);
    ~Rect();
    virtual double getArea();
    virtual void print();
};
