#include <iostream>
#include <string>
#include "character.cpp"

using namespace game;

int main() {
    Warrior warrior("Sir Lancelot");
    warrior.equipWeapon(Sword());
    warrior.acquireSkill(std::move(std::make_unique<HealingTouch>()));

    Mage mage("Merlin");
    mage.acquireSkill(std::make_unique<FireballMastery>());
    mage.equipWeapon(Staff());

    warrior.attack(mage);
    warrior.specialAttack(mage);

    mage.attack(warrior);
    mage.castSpell(warrior);

    return 0;
}
