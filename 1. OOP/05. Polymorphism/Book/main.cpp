#include "Book.h"

int main()
{
    Book *nov = new Novel("The Alchemist");
    Book *bio = new Biography("Paulo Coelho");

    nov->print();
    bio->print();

    delete nov;
    delete bio;
    return 0;
}
