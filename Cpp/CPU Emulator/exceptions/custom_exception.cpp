
#include <exception>

struct custom_exception : public std::exception {

    explicit custom_exception(const char *message) : message(message) {};

    const char *what() const noexcept override {
        return message;
    }

private:
    const char *message;
};

int main() {
    // https://en.cppreference.com/w/cpp/error/exception
    throw custom_exception("Custom exception");
}