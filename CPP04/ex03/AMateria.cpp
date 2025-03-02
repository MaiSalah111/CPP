#include "AMateria.hpp"

AMateria::AMateria()
{
    type = "";
    // std::cout << "AMateria Default Constructor Called" << std::endl; 
}

AMateria::AMateria(std::string const &type) : type(type)
{
    // std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
    // std::cout << "AMateria Copy Constructor Called" << std::endl;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria Destructor Called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if(this != &other)
        this->type = other.type;
    // std::cout << "AMateria Assignement operator Called" << std::endl;
    return (*this);
}

std::string const &AMateria::getType() const
{
    return (type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}

