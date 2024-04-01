#include <iostream>
//
class OtherBase {
    virtual void method(int) = 0;
};

class Base {
public:
    Base() = default;

    void base_method() {
        std::cout << "Public method call\n";
    }

    virtual void print() {
        std::cout << "Base class print\n";
    }

    void show() {
        std::cout << "Base class show\n";
    }

    virtual ~Base() {
        std::cout << "Deleting Base\n";
    }

private:
    int private_field;

protected:
    void protected_method() {
        std::cout << "Protected method call\n";
    }

    int protected_field;
};

class Derived : public Base, virtual public OtherBase {
public:
    Derived() : Base() {
    }

    void method(int a) override {};

    void print() override final {
        protected_method();
        std::cout << "Derived class print\n";
    }

    void show() {
        base_method();
        std::cout << "Derived class show\n";
    }

    void unique_method() {}

    ~Derived() override {
        std::cout << "Deleting derived\n";
    }

    int derived_field;
};

class DerivedDerived : public Derived {
    void print() override {
        protected_method();
        std::cout << "Derived class print\n";
    }
};

int main() {
//    Base base = Derived();

    Base *b_ptr;
    Derived d;
    b_ptr = &d; // Derived* -> Base*
    Derived* d_ptr = new Derived;
    b_ptr = d_ptr;

    b_ptr->print(); // Late binding (output: "Derived class print")
    b_ptr->show();  // Early binding (output: "Base class show")
    return 0;
}
