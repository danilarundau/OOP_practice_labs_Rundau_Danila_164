#include <iostream>

using namespace std;

class BaseClass {
public:
    BaseClass() {
        cout << "BaseClass constructor" << endl;
    }
    ~BaseClass() {
        cout << "BaseClass destructor" << endl;
    }
};

class DerivedClass : public BaseClass {
public:
    DerivedClass() {
        cout << "DerivedClass constructor" << endl;
    }
    ~DerivedClass() {
        cout << "DerivedClass destructor" << endl;
    }
};

int main() {
    BaseClass base;
    DerivedClass derived;

    return 0;
}

