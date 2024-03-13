#include <iostream>

/*
 * Used to add or remove the const qualifier from a variable.
 * Allows modifying the const-ness of an object.
 * */


struct Copy {
    int x = 10;
};

int main() {
    const Copy* copy = new Copy();
//    int y = const_cast<int&>(x); // Removes const from x
//    int* ptr = &x;
    Copy* copy_ = const_cast<Copy*>(copy);
    copy_->x = 100;
    std::cout << copy->x;
}