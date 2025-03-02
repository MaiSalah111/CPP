#include "Animal.hpp"

// Constructor with initialization message
Animal::Animal() : type("") {
    std::cout << "Animal default constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

// Copy assignment operator
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

// Destructor
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// Virtual function for making sound
void Animal::makeSound() const {
    std::cout << "Generic Animal Sound!" << std::endl;
}

// Getter for type
std::string Animal::getType() const {
    return type;
} 