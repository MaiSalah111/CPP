#include "Brain.hpp"

void Brain::printIdeas() const {
    for (int i = 0; i < 5; i++) {
        std::cout << "Idea " << i + 1 << ": " << ideas[i] << "\n";
    }
}

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    // Initialize all ideas
    for (int i = 0; i < 100; i++) {
        ideas[i] = "Empty thought";
    }
    printIdeas();
}

// Deep copy in copy constructor
Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    // Copy each idea individually
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
    printIdeas();
}

// Deep copy in assignment operator
Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
        printIdeas();
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

// Utility functions
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