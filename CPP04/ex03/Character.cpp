#include "Character.hpp"

Character::Character()
{
    name = "";
    for(int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    LinkedInventory = new LinkedList();
    // std::cout << "Character Default Constructor Called" << std::endl;
}

Character::Character(std::string str)
{
    name = str;
    LinkedInventory = new LinkedList;
    for(int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    // std::cout << "Character Parameterized Constructor Called" << std::endl;

}

Character::Character(const Character &copy)
{
    LinkedInventory = new LinkedList;
    this->name = copy.name;
    for(int i = 0; i < 4; i++)
    {
        if(copy.inventory[i])
            inventory[i] = copy.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{
    if(this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            if(inventory[i])
            {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }
        name = other.name;
        for(int i = 0; i < 4; i++)
        {
            if(other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    for(int i = 0; i < 4; i++)
    {
        if(!this->inventory[i])
        {
            this->inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if(idx >= 0 && idx < 4)
    {
        LinkedInventory->addNode(inventory[idx]);
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if(idx>= 0 && idx < 4 && this->inventory[idx])
        this->inventory[idx]->use(target);
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
    {
        if(this->inventory[i])
            delete this->inventory[i];
    }
    delete LinkedInventory;
    // std::cout << "Character Destructor Called" << std::endl;
}