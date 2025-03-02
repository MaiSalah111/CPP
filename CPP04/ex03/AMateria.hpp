#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
    std::string type;

    public:
    AMateria();
    AMateria(const AMateria &copy);
    virtual ~AMateria();

    AMateria &operator=(const AMateria &other);
    
    AMateria(std::string const & type);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};


#endif