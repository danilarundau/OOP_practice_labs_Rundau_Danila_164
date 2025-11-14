#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Shape {
protected:
    string name;
    string color;

public:
    Shape(const string& n, const string& c) : name(n), color(c) {}
    virtual ~Shape() {}

    virtual double area() const = 0;
    virtual void draw() const = 0;

    bool operator==(const Shape& other) const {
        return this->name == other.name && this->color == other.color;
    }

    friend ostream& operator<<(ostream& os, const Shape& shape);
};

ostream& operator<<(ostream& os, const Shape& shape) {
    os << "Name: " << shape.name << ", Color: " << shape.color;
    return os;
}

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const string& n, const string& c, double r) : Shape(n, c), radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    void draw() const override {
        cout << "Drawing Circle: Name=" << name << ", Color=" << color << ", Radius=" << radius << endl;
    }

    Circle operator+(const Circle& other) const {
        return Circle(this->name, this->color, this->radius + other.radius);
    }

    double getRadius() const {
        return radius;
    }
};

int main() {
    Circle myCircle1("Red Circle", "Red", 5.0);
    Circle myCircle2("Blue Circle", "Blue", 10.0);
    Circle myCircle3("Red Circle", "Red", 7.0);

    cout << "Area of Circle 1: " << myCircle1.area() << endl;
    myCircle1.draw();

    cout << "\nArea of Circle 2: " << myCircle2.area() << endl;
    myCircle2.draw();

    return 0;
}
