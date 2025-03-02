#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;  // Forward declaration

class ICharacter {
public:
    virtual ~ICharacter() {}  // Virtual destructor
    virtual std::string const & getName() const = 0;  // Pure virtual
    virtual void equip(AMateria* m) = 0;             // Pure virtual
    virtual void unequip(int idx) = 0;               // Pure virtual
    virtual void use(int idx, ICharacter& target) = 0;  // Pure virtual
};

#endif 