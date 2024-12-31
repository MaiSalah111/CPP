/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:15:13 by maiahmed          #+#    #+#             */
/*   Updated: 2024/12/31 16:15:37 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "\n=== Testing Construction Order ===" << std::endl;
    DiamondTrap diamond("Diamond");
    
    std::cout << "\n=== Testing Inherited Abilities ===" << std::endl;
    diamond.attack("Enemy");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    
    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    DiamondTrap diamond2(diamond);
    diamond2.whoAmI();
    
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 50; ++i) {
        diamond.attack("Enemy");
    }
    
    std::cout << "\n=== Testing Fatal Damage ===" << std::endl;
    diamond.takeDamage(200);
    diamond.attack("Enemy");
    diamond.whoAmI();
    
    std::cout << "\n=== Testing Destruction Order ===" << std::endl;
    return (0);
}