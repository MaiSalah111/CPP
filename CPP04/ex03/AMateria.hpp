#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string type;

public:
    AMateria(std::string const & type);
    virtual ~AMateria();
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);

    std::string const & getType() const;  // Returns type
    virtual AMateria* clone() const = 0;   // Pure virtual
    virtual void use(ICharacter& target);
};

#endif 