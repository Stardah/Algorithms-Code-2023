
#include <memory>
#include <vector>


struct Command {
    int value;
    Command() = default;

    virtual void doSomething() = 0;
};

struct CommandPush : public Command {
    int derivedValue;
    CommandPush() = default;

    void doSomething() override {}
};

struct second;

struct first {
    std::shared_ptr<second> ptr;
};
//struct second {     std::shared_ptr<first> ptr;};
struct second {
    std::weak_ptr<first> ptr;
};


int main() {
    {
        std::shared_ptr<first> a(new first); // counter first = 1
        std::shared_ptr<second> b(new second); // counter second = 1
        a->ptr = b; // counter second = 2
        b->ptr = a; // counter first = 1 // std::shared_ptr<first>*
    }
    {
//        std::vector<Command*> vec_static;
//        vec_static.push_back(new CommandPush());

        std::vector<std::unique_ptr<Command>> objects;
        objects.push_back(std::make_unique<CommandPush>());
        for (auto& obj: objects) {
            obj->doSomething();
        }
    }
}