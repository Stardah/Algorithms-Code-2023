/*
 * Used to add or remove the const qualifier from a variable.
 * Allows modifying the const-ness of an object.
 * */


int main() {
    const int x = 10;
    int y = const_cast<int&>(x); // Removes const from x
}