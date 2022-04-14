#include "Cat.h"

ostream& operator<<(ostream& output, Cat& dog) {
    output <<"Cat information" << endl;
    dog.printStatus();
    return output;
}

istream& operator>>(istream& input, Cat& dog) {
    cout << "Cat information" << endl;
    int age;
    string name, breed;
    int sickness, happiness;
    cout << "Age : "; input >> age;
    cout << "Name : "; input >> name;
    cout << "Sickness : "; input >> sickness;
    cout << "Happiness : "; input >> happiness;
    cout << "Breed of cat : "; input >> breed;

    dog.setAge(age); dog.setName(name); dog.setSickness(sickness); dog.setHappiness(happiness);
    dog.setBreed(breed);
    return input;
}

Cat::Cat(int age, string name, int sickness, int happiness, string breedOfDog) : Animal(age, name, sickness, happiness) {
    setBreed(breedOfDog);
}

Cat::~Cat() {
    cout << getName() << " said : " << "Good bye!" << endl;
}

void Cat::Play() {
    cout << getName() << " playing in the house!!" << endl;
    cout << "Happiness +5  Sickness +3" << endl;
    setHappiness(getHappiness() + 5);
    setSickness(getSickness() + 3);
    cout << endl;
}

void Cat::Sleep() {
    cout << getName() << " is sleeping on a my bed...Zzzzzz" << endl;
    cout << "(Happiness +3  Sickness -4" << endl;
    setHappiness(getHappiness() + 3);
    setSickness(getSickness() - 4);
    cout << endl;
}

void Cat::Eat() {
    cout << getName() << " eat the cat food!!" << endl;
    cout << "Happiness +10  Sickness -2" << endl;
    setHappiness(getHappiness() + 10);
    setSickness(getSickness() - 2);
    cout << endl;
}

void Cat::setBreed(string breed) {
    if (breed.length() > 30) {
        std::cerr << "묘종은 30자 이하로 지어주세요." << std::endl;
        exit(1);
    }
    else {
        this->breedOfCat = breed;
    }
}
const string Cat::getBreed() const { return this->breedOfCat; }
void Cat::printStatus() {
    cout << "[Breed of Cat] : " << getBreed() << endl;
    Animal::printStatus();
}