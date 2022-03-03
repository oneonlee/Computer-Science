#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include <thread>

int main() {
    //cout << setw(10) << setfill("=") << "Welcome to Tamagotchi(다마고치) game" << setw(10) << setfill("=") << endl;
    Cat cat(3, "뚱이", 98, 10, "Mix");
    Dog dog;
    cin >> dog;
    cout << endl;
    //초기 상태 확인
    cout<<dog;
    cout<<cat;

    //Play 함수 테스트
    dog.Play();
    cat.Play();

    //Eat 함수 테스트
    dog.Eat();
    cat.Eat();
    //Sleep 함수 테스트
    dog.Sleep();
    cat.Sleep();

    cout << dog;
    cout << cat;

    return 0;
}