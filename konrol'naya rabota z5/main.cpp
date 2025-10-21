#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(string name, int age) : name(name), age(age) {}
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
protected:
    string name;
    int age;
};

class Employee : public Person {
public:
    Employee(string name, int age, string position, double salary) : Person(name, age), position(position), salary(salary) {}
    void display() {
        Person::display();
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
private:
    string position;
    double salary;
};

class Student : public Person {
public:
    Student(string name, int age, string major, double gpa) : Person(name, age), major(major), gpa(gpa) {}
    void display() {
        Person::display();
        cout << "Major: " << major << endl;
        cout << "GPA: " << gpa << endl;
    }
private:
    string major;
    double gpa;
};

int main() {
    Person* p = new Person("Semen Porvatkin", 19);
    Employee* e = new Employee("Danila Rundau", 19, "Manager", 100000000.0);
    Student* s = new Student("Vlad Sedyschev", 19, "Computer Scince", 4.0);

    p->display();
    cout << endl;
    e->display();
    cout << endl;
    s->display();

    delete p;
    delete e;
    delete s;

    return 0;
}
