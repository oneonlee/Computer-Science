#include "Dog.h"

ostream& operator<<(ostream& output, Dog& dog) {
    output << "Dog information"<< endl;
    dog.printStatus();
    return output;
}

istream& operator>>(istream& input, Dog& dog) {
    cout << "Dog information" << endl;
    int age;
    string name, breed;
    int sickness, happiness;
    cout << "Age : "; input >> age;
    cout << "Name : "; input >> name;
    cout << "Sickness : "; input >> sickness;
    cout << "Happiness : "; input >> happiness;
    cout << "Breed of dog : "; input >> breed;

    dog.setAge(age); dog.setName(name); dog.setSickness(sickness); dog.setHappiness(happiness);
    dog.setBreed(breed);
    return input;
}

Dog::Dog(int age, string name, int sickness, int happiness, string breedOfDog) : Animal(age, name, sickness, happiness) {
    setBreed(breedOfDog);
}

Dog::~Dog() {
    cout << getName() << " said : " << "Good bye!" << endl;
}

void Dog::Play() {
    cout << getName() << " running in the front yard!!" << endl;
    cout << "Happiness +10  Sickness +5" << endl;
    setHappiness(getHappiness() + 10);
    setSickness(getSickness() + 5);
    cout << endl;
}

void Dog::Sleep() {
    cout << getName() << " is sleeping on a pet house...Zzzzzz" << endl;
    cout << "(Happiness +2  Sickness -4" << endl;
    setHappiness(getHappiness() + 2);
    setSickness(getSickness() - 4);
    cout << endl;
}

void Dog::Eat() {
    cout << getName() << " eat the dog food!!" << endl;
    cout << "Happiness +15  Sickness -4" << endl;
    setHappiness(getHappiness() + 15);
    setSickness(getSickness() - 4);
    cout << endl;
}

void Dog::setBreed(string breed) {
    if (breed.length() > 30) {
        std::cerr << "견종은 30자 이하로 지어주세요." << std::endl;
        exit(1);
    }
    else {
        this->breedOfDog = breed;
    }
}
const string Dog::getBreed() const {return this->breedOfDog;}

void Dog::printStatus() {
    cout <<"[Breed of Dog] : " << getBreed() <<  endl;
    Animal::printStatus();
}