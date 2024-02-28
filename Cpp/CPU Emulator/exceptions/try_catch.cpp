

#include <iostream>

int main() {
    try {
        if (std::rand() % 2) {
            throw 3;
        } else {
            throw 3.14;
        }
    } catch (int e) {
        std::cout << e << std::endl;
    } catch (double e) {
        std::cout << e << std::endl;
    } catch (...) { // Почему так делать не стоит?
        std::cout << "Something went wrong" << std::endl;
    }
}