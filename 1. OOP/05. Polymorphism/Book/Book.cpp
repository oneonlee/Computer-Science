#include "Book.h"
#include <iostream>
#include <string>

Book::Book(const std::string &title)
    : title(title)
{
    std::cout << "Call book constructor for " << get_title() << std::endl;
}

Book::~Book()
{
    std::cout << "Call book destructor for " << get_title() << std::endl;
}

std::string Book::get_title() const
{
    return title;
}

void Book::print() const
{
    std::cout << "Book" << std::endl;
}

void Book::set_title(const std::string &title)
{
    this->title = title;
}

Novel::Novel(const std::string &title)
    : Book(title)
{
    std::cout << "Call novel constructor for " << get_title() << std::endl;
}

Novel::~Novel()
{
    std::cout << "Call novel destructor for " << get_title() << std::endl;
}

void Novel::print() const
{
    std::cout << "Novel" << std::endl;
}

Biography::Biography(const std::string &title)
    : Book(title)
{
    std::cout << "Call biography constructor for " << get_title() << std::endl;
}

Biography::~Biography()
{
    std::cout << "Call biography destructor for " << get_title() << std::endl;
}

void Biography::print() const
{
    std::cout << "Biography" << std::endl;
}
