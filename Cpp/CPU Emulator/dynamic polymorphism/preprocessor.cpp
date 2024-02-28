#include <vector>
#include <string>

class Command {
public:
    std::string name;
    std::vector<std::string> args;
};

class Preprocessor {
public:
    std::vector<Command> process() {
        // TODO
        return std::vector<Command>{};
    }
};

/*
 * program:
 * PUSH 10
 * PUSH 20;
 * ADD
 * OUT
 * */