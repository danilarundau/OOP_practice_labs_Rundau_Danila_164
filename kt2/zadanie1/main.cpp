#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(const string& n, const string& c, double w, double h) : Shape(n, c), width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void draw() const override {
        cout << "Drawing Rectangle: Name=" << name << ", Color=" << color << ", Width=" << width << ", Height=" << height << endl;
    }
};

void printInfo(const Shape& shape) {
    cout << "Basic Info: " << shape << endl;
}

void printInfo(const Shape& shape, bool detailed) {
    if (detailed) {
        cout << "Detailed Info: " << shape << endl;
        shape.draw();
    } else {
        printInfo(shape);
    }
}

int main() {
    Circle c1("Red Circle", "Red", 5.0);
    Circle c2("Blue Circle", "Blue", 10.0);
    Rectangle r1("Green Rectangle", "Green", 4.0, 6.0);

    vector<Shape*> shapes;
    shapes.push_back(&c1);
    shapes.push_back(&c2);
    shapes.push_back(&r1);

    cout << "--- Polymorphism Demo ---" << endl;
    for (const auto& shape : shapes) {
        shape->draw();
        cout << "Area: " << shape->area() << endl;
    }
    cout << endl;

    cout << "--- Operator Overloading Demo ---" << endl;
    cout << "c1 == c2: " << (c1 == c2) << endl;

    // Исправленная строка: создание отдельного объекта для сравнения
    Circle c3_for_comparison("Red Circle", "Red", 7.0);
    cout << "c1 == c3_for_comparison: " << (c1 == c3_for_comparison) << endl;
    cout << endl;

    Circle combinedCircle = c1 + c2;
    combinedCircle.draw();
    cout << endl;

    cout << "--- Overloaded Function Demo ---" << endl;
    printInfo(c1);
    printInfo(r1, true);
    printInfo(combinedCircle, false);
    printInfo(combinedCircle, true);
    cout << endl;

    cout << "--- Output Operator Demo ---" << endl;
    cout << c1 << endl;
    cout << combinedCircle << endl;

    return 0;
}
