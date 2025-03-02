#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Virtual behavior demonstration
    const Animal* animal = new Animal();
    std::cout << std::endl;
    const Animal* dog = new Dog();
    std::cout << std::endl;
    const Animal* cat = new Cat();
    std::cout << std::endl;

    std::cout << "\nAnimal Types:" << std::endl;
    std::cout << dog->getType() << std::endl;  // Prints "Dog"
    std::cout << cat->getType() << std::endl;  // Prints "Cat"

    std::cout << "\nAnimal Sounds:" << std::endl;
    dog->makeSound();  // Prints "Haw! Haw!" (virtual function works)
    cat->makeSound();  // Prints "Meow!" (virtual function works)
    animal->makeSound();  // Prints generic sound

    // Non-virtual behavior demonstration
    std::cout << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << std::endl;
    wrongCat->makeSound();  // Prints WrongAnimal sound (no virtual function)

    // Cleanup
    std::cout << std::endl;
    delete animal;
    std::cout << std::endl;
    delete dog;
    std::cout << std::endl;
    delete cat;
    std::cout << std::endl;
    delete wrongCat;

    return 0;
} 