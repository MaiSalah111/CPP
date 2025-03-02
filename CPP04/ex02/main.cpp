#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // This should not compile:
    // Animal test;  // Error: cannot instantiate abstract class
    
    // These should work:
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    
    i->makeSound();
    j->makeSound();
    
    delete j;
    delete i;
    
    return 0;
} 