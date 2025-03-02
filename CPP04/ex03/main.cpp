#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    // me->unequip(1);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}



// int main()
// {
//     std::cout << "\n************** Testing MateriaSource **************\n" << std::endl;
    
//     IMateriaSource* src = new MateriaSource();
    
//     // Test learning more than 4 Materias
//     std::cout << "Learning Materias:" << std::endl;
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(new Ice());  // Should not learn 5th Materia
    
//     // Test creating unknown Materia
//     std::cout << "\nTesting unknown Materia creation:" << std::endl;
//     AMateria* tmp = src->createMateria("unknown");
//     if (tmp == NULL)
//         std::cout << "Successfully returned NULL for unknown Materia" << std::endl;
    
//     std::cout << "\n************** Testing Character Equipment **************\n" << std::endl;
    
//     Character* me = new Character("hero");
    
//     // Test equipping 4 Materias
//     std::cout << "Equipping Materias:" << std::endl;
//     AMateria* m1 = src->createMateria("ice");
//     AMateria* m2 = src->createMateria("cure");
//     AMateria* m3 = src->createMateria("ice");
//     AMateria* m4 = src->createMateria("cure");
//     AMateria* m5 = src->createMateria("ice");
    
//     me->equip(m1);
//     me->equip(m2);
//     me->equip(m3);
//     me->equip(m4);
//     me->equip(m5);  // Should fail - inventory full
    
//     // Test using Materias
//     ICharacter* target = new Character("target");
//     std::cout << "\nUsing Materias:" << std::endl;
//     me->use(0, *target);
//     me->use(1, *target);
//     me->use(2, *target);
//     me->use(3, *target);
//     me->use(4, *target);  // Should fail - invalid index
//     me->use(-1, *target); // Should fail - invalid index
    
//     // Test unequipping
//     std::cout << "\nTesting unequip:" << std::endl;
//     me->unequip(1);  // Unequip cure
//     me->use(1, *target);  // Should do nothing - empty slot
    
//     // Test deep copy
//     std::cout << "\nTesting deep copy:" << std::endl;
//     Character* clone = new Character(*me);
//     clone->use(0, *target);  // Should work - deep copied
//     me->unequip(0);  // Should not affect clone
//     clone->use(0, *target);  // Should still work
    
//     // Test assignment operator
//     std::cout << "\nTesting assignment operator:" << std::endl;
//     Character assignTest("test");
//     assignTest = *me;
//     assignTest.use(2, *target);  // Should work - deep copied
    
//     // Cleanup unequipped Materia to prevent memory leaks
//     delete m5;  // Was never equipped
//     delete m2;  // Was unequipped
    
//     // Cleanup
//     delete target;
//     delete clone;
//     delete me;
//     delete src;
    
//     std::cout << "\nAll tests completed successfully!" << std::endl;
//     return 0;
// }