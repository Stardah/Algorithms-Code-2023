#include <algorithm>
#include <iostream>

template<class T>
class SharedPointer {
public:
    SharedPointer() = delete;

    explicit SharedPointer(T *&&ptr) : ptr(ptr), counter(new size_t(1)) {};

    SharedPointer(SharedPointer &&other) noexcept {
        this = std::move(other);
    };

    SharedPointer &operator=(SharedPointer &&other) noexcept {
        ptr = other.ptr;
        counter = other.counter;
        other.ptr = nullptr;
        other.counter = nullptr;
        return *this;
    };

    SharedPointer(const SharedPointer &other) { // Что может пойти не так?
        ptr = other.ptr;
        counter = other.counter;
        *counter += 1;
    };

    SharedPointer operator=(const SharedPointer &other) = delete;

    T *operator->() const {
        return this->ptr;
    }

    T &operator*() const {
        return this->ptr;
    }

    ~SharedPointer() {
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
    SharedPointer<int> ptr(new int(5));
    std::cout << ptr.getCounter() << std::endl;
    {
        auto ptr2 = ptr;
        std::cout << ptr2.getCounter() << std::endl;
    }
    std::cout << ptr.getCounter() << std::endl;
    return 0;
}