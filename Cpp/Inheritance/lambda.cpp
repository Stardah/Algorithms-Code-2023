#include <functional>
#include <iostream>

struct Foo {
    void bar() {}
};

void bar(std::function<double(int, double)>) {}

int main() {
    int num = 10;

    auto adder = [&, num](int a, int b) -> int { return a + b; };
    std::cout << adder(10, 20) << std::endl;

    auto adderT = [](auto a, auto b) { return a + b; };
    std::cout << adderT(10, 20.5) << std::endl;

    std::function<double(int, double)> adder_func = adderT;
    std::function<void(Foo &)> bar_func = &Foo::bar;
    bar(adder);

    auto other = [](auto adderT) { return adderT(10, 20); };
    std::cout << other(adderT);
    std::cout << other([](auto a, auto b) { return 10; });
}