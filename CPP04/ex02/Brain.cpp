#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    // Initialize all ideas
    for (int i = 0; i < 100; i++) {
        ideas[i] = "Empty thought";
    }
}

// Deep copy in copy constructor
Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    // Copy each idea individually
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

// Deep copy in assignment operator
Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "Invalid idea index";
} 