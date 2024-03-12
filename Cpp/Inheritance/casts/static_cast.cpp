#include <iostream>
#include <typeinfo>

/*
 * The static_cast operator is commonly used for explicit type conversions
 * that are considered safe by the compiler.
 * It performs compile-time type conversion.
 * Used to convert between related types, such as numeric types or pointers
 * in the same inheritance hierarchy.
 * */

int main() {
    int num = 10;
    double numDouble = static_cast<double>(num);
    std::cout << typeid(num).name() << std::endl;
    std::cout << typeid(static_cast<double>(num)).name() << std::endl;
    std::cout << typeid(numDouble).name() << std::endl;
    return 0;
}