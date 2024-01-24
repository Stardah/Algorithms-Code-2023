#include <iostream>
#include <string>
#include <format>

#include "Hello.h"

namespace hello
{
    void print_hello() {
        std::string name;
        std::cin >> name;
        std::cout << std::format("Hello, {}", name) << std::endl;
    }

    int add(int a, int b) {
        return a + b;
    }
}
