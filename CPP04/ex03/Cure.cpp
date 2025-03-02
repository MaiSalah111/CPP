#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
    // std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    if(this != &other)
        this->type = other.type;
    // std::cout << "Cure assignment operator called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    // std::cout << "Cure destructor called" << std::endl;
}


void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}