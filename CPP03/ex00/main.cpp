#include "ClapTrap.hpp"

int main(void)
{
    // Test constructor
    std::cout << "\n=== Testing Constructor ===" << std::endl;
    ClapTrap warrior1("Warrior1");
    
    // Test copy constructor
    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    ClapTrap warrior2(warrior1);
    
    // Test basic attacks
    std::cout << "\n=== Testing Basic Attacks ===" << std::endl;
    warrior1.attack("Target1");
    warrior2.attack("Target2");
    
    // Test damage taking
    std::cout << "\n=== Testing Damage ===" << std::endl;
    warrior1.takeDamage(5);
    warrior1.takeDamage(4);
    
    // Test repairs
    std::cout << "\n=== Testing Repairs ===" << std::endl;
    warrior1.beRepaired(3);
    warrior1.beRepaired(2);
    
    // Test energy point depletion (should be able to attack 8 more times)
    std::cout << "\n=== Testing Energy Point Depletion ===" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        warrior1.attack("Target3");
    }
    // These should fail - no energy points left
    warrior1.attack("Target4");
    warrior1.beRepaired(1);
    
    // Test fatal damage
    std::cout << "\n=== Testing Fatal Damage ===" << std::endl;
    warrior2.takeDamage(15); // More than max HP
    warrior2.attack("Target5"); // Should fail - no hit points
    warrior2.beRepaired(5); // Should fail - no hit points
    
    // Test destructor
    std::cout << "\n=== Testing Destructor ===" << std::endl;
    return (0);
} 

// #include "ClapTrap.hpp"

// int main(void)
// {
//     ClapTrap warrior1("Warrior1");
//     ClapTrap warrior2(warrior1);
    
//     warrior1.attack("Target1");
//     warrior2.attack("Target2");
    
//     warrior1.takeDamage(5);
//     warrior1.takeDamage(4);
    
//     warrior1.beRepaired(3);
//     warrior1.beRepaired(2);
    
//     for (int i = 0; i < 8; ++i)
//         warrior1.attack("Target3");
        
//     warrior1.attack("Target4");
//     warrior1.beRepaired(1);
    
//     warrior2.takeDamage(15);
//     warrior2.attack("Target5");
//     warrior2.beRepaired(5);
    
//     return (0);
// }