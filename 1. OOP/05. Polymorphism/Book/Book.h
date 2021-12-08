#pragma once

#include <string>

class Book
{
private:
    std::string title;

public:
    Book(const std::string &title);
    virtual ~Book();
    std::string get_title() const;
    virtual void print() const;
    void set_title(const std::string &title);
};

class Novel : public Book
{
public:
    Novel(const std::string &title);
    virtual ~Novel();
    virtual void print() const;
};

class Biography : public Book
{
public:
    Biography(const std::string &title);
    virtual ~Biography();
    virtual void print() const;
};
