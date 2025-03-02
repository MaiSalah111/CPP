#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Virtual behavior demonstration
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\nAnimal Types:" << std::endl;
    std::cout << dog->getType() << std::endl;  // Prints "Dog"
    std::cout << cat->getType() << std::endl;  // Prints "Cat"

    std::cout << "\nAnimal Sounds:" << std::endl;
    dog->makeSound();  // Prints "Haw! Haw!" (virtual function works)
    cat->makeSound();  // Prints "Meow!" (virtual function works)
    animal->makeSound();  // Prints generic sound

    // Non-virtual behavior demonstration
    const WrongAnimal* wrongCat = new WrongCat();
    wrongCat->makeSound();  // Prints WrongAnimal sound (no virtual function)

    // Cleanup
    delete animal;
    delete dog;
    delete cat;
    delete wrongCat;

    return 0;
} 