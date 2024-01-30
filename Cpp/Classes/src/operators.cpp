#include <iostream>
#include <format>

struct Counter {

//    Counter() = default;
    explicit Counter(int sec) {
        seconds = sec;
    }

    Counter operator+(Counter other) const {
        return Counter(seconds + other.seconds);
    }

//    // Не обязательно определять оператор на этот класс
    int operator+(int s) const {
        return this->seconds + s;
    }

    bool operator==(Counter other) const {
        return seconds == other.seconds;
    }

    Counter &operator++() {
        seconds += 5;
        return *this;
    }

    // Нужно вернуть ссылку на предыдущее значение!
    Counter operator++(int) {
        Counter prev = *this;
        ++*this;
        return prev;
    }

    int getSeconds() const {
        return seconds;
    }

    // friend функция имеет доступ к приватным членам класса
    friend std::ostream &operator<<(std::ostream &out, const Counter &counter);
private:
    int seconds;
};

std::ostream &operator<<(std::ostream &out, const Counter &counter) {
    out << counter.seconds << " seconds";
    return out;
}

int main() {
    using namespace std;

    Counter c1(10);
    Counter c2(10);
    c1.operator+(c2);
    Counter c3 = c1 + c2;

    int seconds = c1 + 25;
    cout << "c1 + 25 = " << seconds << endl; // c1 + 25 = 45

    cout << "Counter(50) == Counter(50): " << (Counter(50) == Counter(50)) << endl;

    return 0;
}