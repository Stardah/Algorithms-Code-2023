#include <iostream>
#include <variant>
#include <format>

class CatPrinter {
public:
    void printName(std::string parameter) const {
        std::cout << std::format("Hello I am a {} Cat!\n", parameter);
    }
};

class CapybaraPrinter {
public:
    void printName(std::string parameter) const {
        std::cout << std::format("Hello I am a {} Capybara!\n", parameter);
    }
};

struct CallPrintName {
    void operator()(const CatPrinter &catPrinter) { catPrinter.printName(parameter); }
    void operator()(const CapybaraPrinter &capybaraPrinter) { capybaraPrinter.printName(parameter); }

    std::string parameter;
};

int main() {
    std::variant<CatPrinter, CapybaraPrinter> variant;

    variant = CatPrinter{};
//    variant = CapybaraPrinter{};

//    std::visit(CallPrintName{}, variant);
    std::visit(CallPrintName{"lazy"}, variant);

    std::variant<int, double> variant2;
    variant2 = 1;
    variant2 = 1.0;
    std::cout << std::get<double>(variant2);
    return 0;
}

