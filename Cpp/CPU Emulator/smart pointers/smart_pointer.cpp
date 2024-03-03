#include <algorithm>
#include <memory>
#include <vector>

template<class T>
class UniquePointer {
public:
    UniquePointer() = delete;

    explicit UniquePointer(T *&&ptr) : ptr(ptr) {};
//    explicit UniquePointer(T ptr[]) : ptr(ptr), isArray(true) {};


    UniquePointer(UniquePointer &&other) noexcept {
        this = std::move(other);
    };

    UniquePointer &operator=(UniquePointer &&other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    };

    UniquePointer(const UniquePointer &) = delete;

    UniquePointer operator=(const UniquePointer &) = delete;

    T *operator->() const {
        return this->ptr;
    }

    T &operator*() const {
        return this->ptr;
    }

    ~UniquePointer() { // В каких случаях не сработает?
//        isArray ? delete[] ptr : delete ptr;
        delete ptr;
    };

private:
    T *ptr;
    bool isArray = false;
};

int main() {
    {
        auto ptr = std::make_unique<std::vector<int>>(5);
//        std::unique_ptr<std::vector<int>>
        // То же самое:
        std::vector<int> *vec = new std::vector<int>(5);
        UniquePointer<std::vector<int>> ptr_(std::move(vec));
        std::unique_ptr<int> ptr2(new int(5));
        ptr_->push_back(12);
//        std::vector<int>* vec(5);
    }
}