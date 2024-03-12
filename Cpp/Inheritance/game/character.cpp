#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <format>

#include "abilities.cpp"
#include "weapons.cpp"
#include "stats.cpp"

namespace game {
    class Skill;

    // Base class for characters
    class Character {
    public:
        Character(std::string name, int health, int attackPower, int defence) : name(std::move(name)) {
            stats.health = health;
            stats.attack = attackPower;
            stats.defence = defence;
        }

        void attack(Character &target) {
            auto newStats = stats;
            for (const auto &skill: skills) {
                if (skill->isActive()) {
                    skill->applyEffect(newStats);
                }
            }
            std::cout << std::format("{} attacks {} with {} power!", name, target.getName(), stats.attack) << std::endl;
            double damage = newStats.attack - target.getStats().defence;
            target.takeDamage(damage);
        }

        void equipWeapon(const Weapon &newWeapon) {
            weapon = newWeapon;
            std::cout << name << std::format(" equips a {}!", weapon.getName()) << std::endl;
        }

        void acquireSkill(std::unique_ptr<Skill> &&skill) {
            std::cout << std::format("{} learns a new skill \"{}\"!",name, skill->getName()) << std::endl;
            skills.push_back(std::move(skill));
        }

        void heal(int amount) {
            stats.health += amount;
            std::cout << name << " heals for " << amount << " health!" << std::endl;
        }

        void takeDamage(double damage) {
            stats.health -= damage;
            std::cout << name << " takes " << damage << " damage!" << std::endl;
        }

        Stats& getStats() {
            return stats;
        }

        const std::string &getName() const {
            return name;
        }

    protected:
        std::string name;
        Stats stats{};

        std::vector<std::unique_ptr<Skill>> skills;
        Weapon weapon = Fists();
    };

// Derived class for warriors
    class Warrior : public Character {
    public:
        explicit Warrior(const std::string &name) : Character(name, 100, 30, 20) {}

        void specialAttack(Character& enemy) {
            std::cout << name << " performs a mighty sword strike!" << std::endl;
            this->attack(enemy);
        }

        void useShieldBash() {
            stats.attack *= 1.5; // Increase attack power by 50%
            std::cout << name << " uses Shield Bash! Attack power increased!" << std::endl;
        }
    };

// Derived class for mages
    class Mage : public Character {
    public:
        explicit Mage(const std::string &name) : Character(name, 80, 50, 10) {}

        void castSpell(Character& target) {
            std::cout << name << " casts a powerful fireball spell!" << std::endl;
            this->attack(target);
        }

        void useFireball() {
            stats.attack *= 1.5; // Increase attack power by 50%
            std::cout << name << " uses Fireball! Attack power increased!" << std::endl;
        }
    };

    class Archer : public Character {
    public:
        explicit Archer(const std::string &name) : Character(name, 70, 25, 20) {}

        void shootArrow() {
            std::cout << name << " releases a deadly arrow!" << std::endl;
        }
    };

    class Thief : public Character {
    public:
        explicit Thief(const std::string &name) : Character(name, 60, 20, 5) {}

        void steal() {
            std::cout << name << " silently pilfers from the enemy!" << std::endl;
        }
    };
}