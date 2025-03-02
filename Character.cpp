#include "Character.hpp"

Character::Character(std::string const & name) : name(name), droppedCount(0) {
    for (int i = 0; i < MAX_SLOTS; i++)
        inventory[i] = NULL;
    for (int i = 0; i < MAX_DROPPED; i++)
        dropped[i] = NULL;
}

Character::Character(Character const & other) : name(other.name), droppedCount(0) {
    // Initialize everything to NULL first
    for (int i = 0; i < MAX_SLOTS; i++)
        inventory[i] = NULL;
    for (int i = 0; i < MAX_DROPPED; i++)
        dropped[i] = NULL;
    
    // Then copy the inventory
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
}

Character::~Character() {
    // Clean up inventory
    for (int i = 0; i < MAX_SLOTS; i++) {
        delete inventory[i];
        inventory[i] = NULL;
    }
    // Clean up dropped items
    for (int i = 0; i < droppedCount; i++) {
        delete dropped[i];
        dropped[i] = NULL;
    }
}

Character& Character::operator=(Character const & other) {
    if (this != &other) {
        // Clean up existing inventory
        for (int i = 0; i < MAX_SLOTS; i++) {
            delete inventory[i];
            inventory[i] = NULL;
        }
        
        // Clean up dropped items
        for (int i = 0; i < droppedCount; i++) {
            delete dropped[i];
            dropped[i] = NULL;
        }
        droppedCount = 0;
        
        // Copy name and materias
        name = other.name;
        for (int i = 0; i < MAX_SLOTS; i++) {
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            }
        }
    }
    return *this;
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
        
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
    // If we couldn't equip it, delete it
    delete m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= MAX_SLOTS || !inventory[idx] || droppedCount >= MAX_DROPPED)
        return;
        
    dropped[droppedCount++] = inventory[idx];
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < MAX_SLOTS && inventory[idx])
        inventory[idx]->use(target);
}

std::string const & Character::getName() const {
    return name;
} 