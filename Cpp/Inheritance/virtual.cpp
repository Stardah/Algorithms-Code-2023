#include <iostream>
using namespace std;

class Base {
public:
    virtual void print() {
        cout << "Base class print\n";
    }
    void show() {
        cout << "Base class show\n";
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived class print\n";
    }
    void show() {
        cout << "Derived class show\n";
    }
};

int main() {
    Base *b_ptr;
    Derived d;
    b_ptr = &d;
    b_ptr->print(); // Late binding (output: "Derived class print")
    b_ptr->show();  // Early binding (output: "Base class show")
    return 0;
}
