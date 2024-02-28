
#include <memory>
#include <vector>

struct second;

struct first { std::shared_ptr<second> ptr;};
//struct second { std::shared_ptr<first> ptr;};
struct second { std::weak_ptr<first> ptr;};

struct Base {
    int value;
    virtual void doSomething() = 0;
};

struct Derived : public Base {
    int derivedValue;
    void doSomething() override {}
};

int main() {
//    {
//        std::unique_ptr<first> unique = std::make_unique<first>();
//    }
    {
        std::shared_ptr<first> a(new first); // counter first = 1
        std::shared_ptr<second> b(new second); // counter second = 1
        a->ptr = b; // counter second = 2
        b->ptr = a; // std::shared_ptr<first>*
    }
    {
        std::vector<std::unique_ptr<Base>> objects;
        objects.push_back(std::make_unique<Derived>());
        for (auto& obj: objects) {
            obj->doSomething();
        }
    }
}