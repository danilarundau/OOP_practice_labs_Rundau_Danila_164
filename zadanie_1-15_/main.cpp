#include<iostream>
#include<vector>
#include<memory>
using namespace std;

// Абстрактный базовый класс Dokument
class Dokument {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual ~Dokument() {} // Виртуальный деструктор
};

// Производный класс TextDocument
class TextDocument : public Dokument {
public:
    void open() override {
        cout << "Opening Text Document\n";
    }
    void close() override {
        cout << "Closing Text Document\n";
    }
};

// Производный класс SpreadsheetDocument
class SpreadsheetDocument : public Dokument {
public:
    void open() override {
        cout << "Opening Spreadsheet Document\n";
    }
    void close() override {
        cout << "Closing Spreadsheet Document\n";
    }
};

// Абстрактный базовый класс Application
class Application {
public:
    virtual unique_ptr<Dokument> createDocument() = 0;
    virtual ~Application() = default;
};

// Производный класс TextApplication
class TextApplication : public Application {
public:
    unique_ptr<Dokument> createDocument() override {
        return make_unique<TextDocument>();
    }
};

// Производный класс SheetApplication
class SheetApplication : public Application {
public:
    unique_ptr<Dokument> createDocument() override {
        return make_unique<SpreadsheetDocument>();
    }
};

// Существующие классы Shape, Rectangle, Circle
class Shape {
protected:
    int x;
    int y;
public:
    Shape(int x, int y) : x(x), y(y) {
        cout << "Shape constructor called for (" << x << "," << y << ")\n";
    }
    virtual void draw() = 0;
    void move(int newX, int newY) { x = newX; y = newY; }
    virtual ~Shape() {
        cout << "Shape destructor called for (" << x << "," << y << ")\n";
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int x, int y) : Shape(x, y) {
        cout << "Rectangle constructor called for (" << x << "," << y << ")\n";
    }
    void draw() override { cout << "Drawing Rectangle at (" << x << "," << y << ")\n"; }
    ~Rectangle() {
        cout << "Rectangle destructor called for (" << x << "," << y << ")\n";
    }
};

class Circle : public Shape {
public:
    Circle(int x, int y) : Shape(x, y) {}
    void draw() override { cout << "Drawing Circle at (" << x << "," << y << ")\n"; }
};

int main() {
    vector<Shape*> shapes = {
        new Rectangle(10, 20),
        new Circle(30, 40)
    };

    Shape* rectPtr = new Rectangle(100, 200);
    rectPtr->draw();
    delete rectPtr;

    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
        shapes[i]->move(i + 10, i + 20);
    }

    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }

    // Демонстрация работы с классами Application
    Application* app = new TextApplication();
    unique_ptr<Dokument> doc = app->createDocument();
    doc->open();
    doc->close();
    delete app;
}

