#include "Shape.h"
#include <iomanip>

int main()
{
    Shape *shape1;
    Shape *shape2;
    Shape *shape3;

    Circle c(1.2);
    Square s(3.2);
    Rect r(2.1, 3.4);

    shape1 = &c;
    shape2 = &s;
    shape3 = &r;

    shape1->print();
    shape2->print();
    shape3->print();
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area of shape1 : " << shape1->getArea() << std::endl;
    std::cout << "Area of shape2 : " << shape2->getArea() << std::endl;
    std::cout << "Area of shape3 : " << shape3->getArea() << std::endl;

    return 0;
}