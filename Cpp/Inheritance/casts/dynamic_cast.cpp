#include <iostream>

/*
    Used mainly for downcasting (converting a pointer/reference of a base class to a derived class).
    Ensures type safety by performing a runtime check to verify the validity of the conversion.
    If the conversion is not possible, dynamic_cast returns a null pointer (for pointer conversions)
    or throws a bad_cast exception (for reference conversions).
*/

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks." << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Dog barks." << std::endl;
    }

    void jump() {
        std::cout << "Dog jumps." << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Cat meows." << std::endl;
    }
};

int main() {
    Animal* animalPtr = new Dog();

    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);
    if (dogPtr) {
        dogPtr->jump();
    } else {
        std::cout << "Failed to cast to Dog." << std::endl;
    }

    Cat* catPtr = dynamic_cast<Cat*>(animalPtr);
    if (catPtr) {
        catPtr->speak();
    } else {
        std::cout << "Failed to cast to Cat." << std::endl;
    }

    delete animalPtr;
    return 0;
}