#pragma once
#include <iostream>
#include <string>
#include <format>

namespace game {

    class Weapon {
    public:
        Weapon(const std::string &name, int damage, int range) : name(name), damage(damage), range(range) {}

        void attack() {
            std::cout << "Attacking with " << name << " (Damage: " << damage << ")" << std::endl;
        }

        std::string &getName() {
            return name;
        }

    protected:
        std::string name;
        int damage;
        int range;
    };

    class Fists : public Weapon {
    public:
        Fists() : Weapon("Fists", 10, 0) {}
    };

    class Sword : public Weapon {
    public:
        Sword() : Weapon("Sword", 40, 1) {}
    };

    class Bow : public Weapon {
    public:
        Bow() : Weapon("Bow", 30, 5) {}
    };

    class Staff : public Weapon {
    public:
        Staff() : Weapon("Staff", 35, 8) {}
    };
}