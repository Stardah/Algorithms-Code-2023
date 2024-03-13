#include <iostream>

/*
 * Used for low-level type conversions that reinterpret the bit pattern of an object.
 * Not recommended for general use due to its potential for undefined behavior.
 * */

int main() {
    int num = 42;
    double *doublePtr = reinterpret_cast<double *>(&num);
    delete doublePtr;
    doublePtr[0] = 10;
}