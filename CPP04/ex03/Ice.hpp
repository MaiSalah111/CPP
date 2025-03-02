#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria{
    public:
    Ice();
    Ice(const Ice &copy);
    ~Ice();

    Ice(const std::string &type);
    Ice &operator=(const Ice &other);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif