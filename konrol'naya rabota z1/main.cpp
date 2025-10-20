#include <iostream>
#include <string>
#include <locale>
using namespace std;


class Animal {
public:
    virtual void sound() {
        cout << "Неизвестный звук животного" << endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Гав-гав!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Мяу!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "russian");
    Animal* animal = new Animal();
    Dog* dog = new Dog();
    Cat* cat = new Cat();

    cout << "Animal: ";
    animal->sound();
    cout << "Dog: ";
    dog->sound();
    cout << "Cat: ";
    cat->sound();

    Animal* animalDog = new Dog();
    cout << "Animal (Dog): ";
    animalDog->sound();

    delete animal;
    delete dog;
    delete cat;
    delete animalDog;

    return 0;
}
