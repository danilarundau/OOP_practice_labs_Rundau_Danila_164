#include <iostream>
#include <string>

using namespace std;

// Структура для представления точки
struct Point {
    double x;
    double y;

    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

// Класс ColoredPoint, наследующийся от Point
class ColoredPoint : public Point {
public:
    string color;

    ColoredPoint(double x_val = 0.0, double y_val = 0.0, string color_val = "black") :
        Point(x_val, y_val), color(color_val) {
    }

    void print() const {
        Point::print();
        cout << " Color: " << color;
    }
};

int main() {
    Point p(1.0, 2.0);
    cout << "Point: ";
    p.print();
    cout << endl;

    ColoredPoint cp(3.0, 4.0, "red");
    cout << "Colored Point: ";
    cp.print();
    cout << endl;

    return 0;
}
