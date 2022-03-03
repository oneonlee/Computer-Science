#include "Animal.h"

Animal::Animal(int age, string name, int sickness, int happiness) {
    //set 함수를 통한 초기화
    setAge(age);
    setName(name);
    setSickness(sickness);
    setHappiness(happiness);
}

Animal::Animal(Animal& copy) {
    //set 함수를 통한 초기화
    setAge(copy.getAge());
    setName(copy.getName());
    setSickness(copy.getSickness());
    setHappiness(copy.getHappiness());
}

Animal::~Animal() {}

void Animal::Eat() {
    std::cout << "Eating something...\n";
}

void Animal::Play() {
    std::cout << "Playing somewhere...\n";
}

void Animal::Sleep() {
    std::cout << "Sleeping somewhere...\n";
}



void Animal::setAge(int age) {
    this->Age = age > 0 ? age : 1;
}

void Animal::setName(string name) {
    if (name.length() > 20) {
        std::cerr << "이름은 20자 이하로 지어주세요." << std::endl;
        exit(1);
    }
    else {
        this->Name = name;
    }
}

void Animal::setSickness(int sickness) {
    if (sickness >= 0) {
        if (sickness < 100) {
            this->Sickness = sickness;
        }
        else {
            this->Sickness = 99;
            std::cout << getName() << " have to go to the animal hospital...!" << std::endl;

        }
    }
    else {
        this->Sickness = 0;
    }
}

void Animal::setHappiness(int happiness) {
    if (happiness <=100) {
        if (happiness> 0) {
            this->Happiness = happiness;
        }
        else {
            this->Happiness = 0;
            std::cout << getName() << " may be unhappy..." << std::endl;
        }
    }
    else {
        this->Happiness = 100;
    }
}

int Animal::getAge() const {return this->Age;}
const string Animal::getName() const { return this->Name;}
int Animal::getSickness() const { return this->Sickness; }
int Animal::getHappiness() const { return this->Happiness; }


void Animal::printStatus() {
    cout << "[Status]" << endl;
    cout << "Name : " << getName() << " Age : " << getAge() << endl;
    cout << "Happiness : " << getHappiness() << " Sickness : " << getSickness() << endl;
    cout << endl;

}