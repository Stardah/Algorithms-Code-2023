#include <iostream>

// В основном используются как сущность для хранения переменных, но может использоваться как класс
// Отличие от класса - по умолчанию все public, у класса - private

struct Point {
    int x;
    int y;

    Point(long long x, long long y) : x(static_cast<int>(x)), y(y) {}

    void print() {}
    int print(int x) {
        this->y;
        int int_value = 10;
        long long int long_value = (long long) int_value;
    }
    long print(int x, int y) { return x + y; }
    int print(long x, int y) {}
};


int main() {
    Point p(10, 10);
    std::cout << p.x;
    p.print(10, 10);
//    p.y;
    return 0;
}