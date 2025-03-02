#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain(); // Create new Brain
}

// Deep copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // Create new Brain as copy
}

// Deep copy assignment
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain; // Delete old brain
        brain = new Brain(*other.brain); // Create new brain as copy
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain; // Clean up Brain
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
} 