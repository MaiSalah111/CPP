#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
    if(this != &other)
        this->type = other.type;
    // std::cout << "Ice assignment operator called" << std::endl;
    return (*this);
}

Ice::~Ice()
{
    // std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const std::string &type) : AMateria(type) { }


void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}
