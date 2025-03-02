#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");
    
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
    
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }

int main()
{
    std::cout << "=== Basic Tests (from subject) ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n=== Additional Tests ===" << std::endl;
    
    // Test learning more than 4 Materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());  // Should not learn (full)
    
    // Test creating unknown Materia
    tmp = src->createMateria("fire");  // Should return NULL
    if (!tmp)
        std::cout << "Successfully returned NULL for unknown Materia" << std::endl;

    // Test full inventory
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);  // Should do nothing (inventory full)
    delete tmp;      // Clean up unused materia

    // Test deep copy
    Character* charles = new Character("charles");
    tmp = src->createMateria("ice");
    charles->equip(tmp);
    
    Character* charles_copy = new Character(*charles);
    charles->unequip(0);
    
    std::cout << "Original character uses empty slot (should do nothing):" << std::endl;
    charles->use(0, *bob);
    std::cout << "Copied character uses Ice (should work):" << std::endl;
    charles_copy->use(0, *bob);

    delete charles_copy;
    delete charles;
    delete bob;
    delete me;
    delete src;

    return 0;
}
