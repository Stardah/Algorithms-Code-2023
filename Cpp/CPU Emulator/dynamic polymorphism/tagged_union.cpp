#include <iostream>

enum class Tags {
    Car,
    House,
    Poetry,
};

struct TaggedUnion {
    Tags tag;
    union DataUnion {
        struct {
            std::string model;
            void print() { std::cout << "Model: " << model << std::endl; }
        } car;

        struct {
            int number;
            std::string street;
            void print() { std::cout << "Model: " << number << std::endl; }
        } house;

        std::string poetry;

        ~DataUnion() {};
    } data;
};

int main() {
    TaggedUnion tagged_union = {.tag = Tags::House, .data = {.poetry = "Hello"}};

    switch (tagged_union.tag) {
    case Tags::Car:
        tagged_union.data.car.print();
        break;
    case Tags::House:
        tagged_union.data.house.print();
        break;
    case Tags::Poetry:
        std::cout << tagged_union.data.poetry << std::endl;
        break;
    }

    std::cout << tagged_union.data.poetry << std::endl;
    return 0;
}
