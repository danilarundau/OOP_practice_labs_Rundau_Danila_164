#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    Vehicle(string brand, string model) : brand(brand), model(model) {}
    virtual void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
    virtual ~Vehicle() {}
protected:
    string brand;
    string model;
};

class Car : public Vehicle {
public:
    Car(string brand, string model, int doors) : Vehicle(brand, model), doors(doors) {}
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Doors: " << doors << endl;
    }
private:
    int doors;
};

class Bicycle : public Vehicle {
public:
    Bicycle(string brand, string model, bool basket) : Vehicle(brand, model), basket(basket) {}
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Basket: " << (basket ? "Yes" : "No") << endl;
    }
private:
    bool basket;
};

int main() {
    Vehicle* v = new Vehicle("Generic", "Vehicle");
    Car* c = new Car("Toyota", "Corolla", 4);
    Bicycle* b = new Bicycle("Giant", "Defy", true);

    v->displayInfo();
    c->displayInfo();
    b->displayInfo();

    Vehicle* vc = new Car("Honda", "Civic", 2);
    vc->displayInfo();

    delete v;
    delete c;
    delete b;
    delete vc;

    return 0;
}
