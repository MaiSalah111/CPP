#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "LinkedList.hpp"

class Character : public ICharacter{
    private:
    std::string name;
    LinkedList *LinkedInventory;
    AMateria *inventory[4];

    public:
    Character();
    Character(std::string str);
    Character(const Character &copy);
    ~Character();

    Character &operator=(const Character &other);

    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif