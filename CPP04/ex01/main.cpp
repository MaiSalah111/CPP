#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // std::cout << "\n************** Creating Array of Animals **************" << std::endl;
    
    // const int numAnimals = 4;
    // Animal* animals[numAnimals];
    
    // // Create half dogs and half cats
    // for (int i = 0; i < numAnimals; i++) {
    //     if (i < numAnimals/2)
    //         animals[i] = new Dog();
    //     else
    //         animals[i] = new Cat();
    // }
    
    // // Delete all animals
    // for (int i = 0; i < numAnimals; i++) {
    //     delete animals[i];
    // }
    
    // std::cout << "\n************** Testing Deep Copy **************" << std::endl;
    
    // Dog* dog1 = new Dog();
    // dog1->getBrain()->setIdea(0, "I love bones!");
    
    // Dog* dog2 = new Dog(*dog1); // Deep copy constructor
    // delete dog1;
    
    // // dog2 should still have access to its ideas
    // std::cout << "Dog2's first idea: " << dog2->getBrain()->getIdea(0) << std::endl;
    // delete dog2;

        Dog basic;
    {
        Dog tmp = basic;
    }

    
    return 0;
} 