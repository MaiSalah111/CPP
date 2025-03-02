#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain(); // Create new Brain
}

// Deep copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // Create new Brain as copy
}

// Deep copy assignment
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain; // Delete old brain
        brain = new Brain(*other.brain); // Create new brain as copy
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain; // Clean up Brain
}

void Dog::makeSound() const {
    std::cout << "Haw! Haw!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
} 