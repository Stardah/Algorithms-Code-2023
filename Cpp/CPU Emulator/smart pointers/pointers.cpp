#include <stdexcept>
#include <vector>
#include <iostream>

void unsafe_function() {
    if (rand() % 2 == 0) {
        throw std::runtime_error("Something went wrong");
    }
}

void do_something() {
    auto *v = new std::vector<int>(10);
    unsafe_function();
    delete v;
}

int* unsafe_allocator() {
    if (rand() % 2 == 0) {
        throw std::runtime_error("Something went wrong");
    }
    return new int[10];
}

struct unsafe_class {
    int* ptr;
    int* ptr2;

    unsafe_class() { // Как решить проблему?
        ptr = new int[10];
        ptr2 = unsafe_allocator();
    }

    ~unsafe_class() {
        delete ptr;
        delete ptr2;
    }
};

int main() {
    try {
        do_something();
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        unsafe_class u;
        std::cout << "No exception" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}