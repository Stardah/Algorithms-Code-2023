#include <iostream>

// В основном используются как сущность для хранения переменных, но может использоваться как класс
// Отличие от класса - по умолчанию все public, у класса - private

struct Point {
    Point() = delete;
    Point(int x, int y) : x(x), y(y) {}
    int x;
    int y;

    void print() {}
    int print(int x) {}
    long print(int x, int y) {}
    int print(long x, int y) {}
};


int main() {
    Point p(1, 2);
//    p.y;
    return 0;
}