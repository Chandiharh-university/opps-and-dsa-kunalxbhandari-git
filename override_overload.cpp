#include <iostream>
using namespace std;

// Base class
class Base {
public:
    // Function to be overridden
    virtual void display() {
        cout << "This is the Base class display method." << endl;
    }

    // Function overloading example
    void add(int a, int b) {
        cout << "Sum of two integers: " << a + b << endl;
    }

    void add(double a, double b) {
        cout << "Sum of two doubles: " << a + b << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    // Function overriding example
    void display() override {
        cout << "This is the Derived class display method." << endl;
    }
};

int main() {
    // Function overloading demonstration
    Base base;
    base.add(3, 4);         // Calls add(int, int)
    base.add(3.5, 4.5);     // Calls add(double, double)

    // Function overriding demonstration
    Base* basePtr;          // Base class pointer
    Derived derivedObj;

    basePtr = &derivedObj;  // Pointer points to Derived object
    basePtr->display();     // Calls Derived class display due to overriding

    return 0;
}
