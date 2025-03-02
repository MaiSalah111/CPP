#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

// Base class Animal - demonstrates polymorphism through virtual functions
class Animal {
protected:
    std::string type; // Protected attribute as specified

public:
    // Orthodox Canonical Form requirements
    Animal(); // Default constructor
    Animal(const Animal& other); // Copy constructor
    Animal& operator=(const Animal& other); // Copy assignment operator
    virtual ~Animal(); // Virtual destructor for proper cleanup

    // Main member functions
    virtual void makeSound() const; // Virtual function for polymorphic behavior
    std::string getType() const; // Getter for type
};

#endif 