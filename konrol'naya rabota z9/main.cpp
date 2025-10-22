#include <iostream>
#include <string>

using namespace std;

class Human {
public:
    string name;
    int age;

    Human(string name_val = "Unknown", int age_val = 0) : name(name_val), age(age_val) {}

    void print() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

class Employee : public Human {
public:
    string position;

    Employee(string name_val = "Unknown", int age_val = 0, string position_val = "Trainee") :
        Human(name_val, age_val), position(position_val) {}

    void print() const {
        Human::print();
        cout << ", Position: " << position;
    }
};

int main() {
    Human h("Alice", 30);
    cout << "Human: ";
    h.print();
    cout << endl;

    Employee e("Bob", 25, "Software Engineer");
    cout << "Employee: ";
    e.print();
    cout << endl;

    return 0;
}

