#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

// Deep copy constructor
Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
    }
}

// Deep copy assignment
Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        // Delete current inventory
        for (int i = 0; i < 4; i++) {
            delete inventory[i];
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        delete inventory[i];
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        // Just unequip, don't delete
        inventory[idx] = NULL;
        // Note: The caller is responsible for handling the unequipped Materia
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
} 