#pragma once
#include "stats.cpp"
#include <iostream>
#include <string>

namespace game {
    class Skill {
    public:
        Skill(const std::string &name, const std::string &description) : name(name), description(description) {}

        void setActive(bool value) {
            active = value;
        }

        [[nodiscard]] bool isActive() const {
            return active;
        }

        [[nodiscard]] const std::string &getName() const {
            return name;
        }

        virtual void applyEffect(Stats &target) = 0; // Pure virtual function

    protected:
        std::string name;
        std::string description;
        bool active = false;
    };

    class HealingTouch : public Skill {
    public:
        HealingTouch() : Skill("Healing Touch", "Restores health to the target") {}

        void applyEffect(Stats &stats) override {
            stats.health += 50; // Assume a method to heal characters
            std::cout << std::format("Healed {}hp!", stats.health) << std::endl;
        }
    };

    class FireballMastery : public Skill {
    public:
        FireballMastery() : Skill("Fireball Mastery", "Enhances fireball spell damage") {}

        void applyEffect(Stats &stats) override {
            stats.attack *= 1.5;
            std::cout << "Enhanced fireball attack power!" << std::endl;
        }
    };
}
