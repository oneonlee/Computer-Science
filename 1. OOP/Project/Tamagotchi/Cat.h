#pragma once
#include "Animal.h"

class Cat : public Animal {
    friend ostream& operator<<(ostream&, Cat&);
    friend istream& operator>>(istream&, Cat&);
private:
    string breedOfCat;
    void printStatus();
public:
    Cat(int = 1, string = "None", int = 0, int = 50, string = "Mix");
    ~Cat();

    //@Override functions
    void Play();
    void Sleep();
    void Eat();

    void setBreed(string);
    const string getBreed() const;
};