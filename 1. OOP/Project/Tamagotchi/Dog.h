#pragma once
#include "Animal.h"

class Dog : public Animal {
    friend ostream& operator<<(ostream&, Dog&);
    friend istream& operator>>(istream&, Dog&);
private:
    string breedOfDog; // ฐ฿มพ
    void printStatus();
public:
    Dog(int=1, string="None", int=0, int=50, string="Mix");
    ~Dog();
   
    //@Override functions
    void Play();
    void Sleep();
    void Eat();

    void setBreed(string);
    const string getBreed() const;
};