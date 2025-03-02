#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    // Same Orthodox Canonical Form...
    
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();

    // This won't be called through WrongAnimal pointer
    void makeSound() const; // Not virtual, demonstrates wrong behavior
};

#endif 