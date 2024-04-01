#include <functional>
#include <iostream>

template<class T>
struct Foo {
//    auto bar(auto b, auto a) {}
    void bar(T&& a) {
        a = 10;
    }
};

void bar(std::function<double(int, double)>) {}

int main() {
    int num = 10;
    int num2 = 10;

    auto adder = [&](int a, int b) -> int { return a + b + num; };
    std::cout << adder(10, 20) << std::endl;

    auto adderT = [&](auto a, auto b) { return a + b; };
    std::cout << adderT(10, 20.5) << std::endl;
    std::cout << adderT(20, "wd") << std::endl;

    std::function<double(int, double)> adder_func = adderT;
    std::function<void(Foo &)> bar_func = &Foo::bar;
    bar(adder);

//    Foo foo;
//    foo.bar(13, 20.9);

    auto other = [](auto adderT) { return adderT(10, 20); };
    std::cout << other(adderT);
    std::cout << other([](auto a, auto b) { return 10; });
}