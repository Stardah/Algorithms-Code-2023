#include <algorithm>
#include <iostream>

template<class T>
class UniquePointer {
public:
    UniquePointer() = delete;

    explicit UniquePointer(T *&&ptr) : ptr(ptr), counter(new size_t(1)) {};

    UniquePointer(UniquePointer &&other) noexcept {
        this = std::move(other);
    };

    UniquePointer &operator=(UniquePointer &&other) noexcept {
        ptr = other.ptr;
        counter = other.counter;
        other.ptr = nullptr;
        other.counter = nullptr;
        return *this;
    };

    UniquePointer(const UniquePointer &other) { // Что может пойти не так?
        ptr = other.ptr;
        counter = other.counter;
        *counter += 1;
    };

    UniquePointer operator=(const UniquePointer &other) = delete;

    T *operator->() const {
        return this->ptr;
    }

    T &operator*() const {
        return this->ptr;
    }

    ~UniquePointer() {
        *counter -= 1;
        if (*counter == 0) {
            delete ptr;
            delete counter;
        }
    };

    [[nodiscard]] size_t getCounter() const {
        return *counter;
    }

private:
    T *ptr = nullptr;
    size_t *counter = nullptr;
};

int main() {
    UniquePointer<int> ptr(new int(5));
    std::cout << ptr.getCounter() << std::endl;
    {
        auto ptr2 = ptr;
        std::cout << ptr2.getCounter() << std::endl;
    }
    std::cout << ptr.getCounter() << std::endl;
    return 0;
}