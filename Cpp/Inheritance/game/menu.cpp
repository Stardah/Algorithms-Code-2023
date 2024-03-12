#include <iomanip> // For setw()
#include <iostream>
#include <vector>

struct Attack {
    std::string name;
    int power;
};

void printAttackList(const std::vector<Attack> &attacks) {
    std::cout << "Attack Types:\n";
    std::cout << std::left << std::setw(20) << "Name"
              << "Power\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n"; // Separator line

    for (const auto &attack : attacks) {
        std::cout << std::left << std::setw(20) << attack.name << attack.power << "\n";
    }
}

int main() {
    std::vector<Attack> attackList = {
        {"Ember", 40},
        {"Thunderbolt", 90},
        {"Water Gun", 50},
        // Add more attacks here...
    };

    printAttackList(attackList);

    return 0;
}
