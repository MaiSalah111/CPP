/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:09:49 by maiahmed          #+#    #+#             */
/*   Updated: 2024/12/31 16:09:50 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "\n=== Testing Construction Order ===" << std::endl;
    ScavTrap scav("Scavvy");
    
    std::cout << "\n=== Testing ScavTrap Abilities ===" << std::endl;
    scav.attack("Enemy");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();
    
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 25; ++i) {
        scav.attack("Enemy");
    }
    
    std::cout << "\n=== Testing Fatal Damage ===" << std::endl;
    scav.takeDamage(200);
    scav.attack("Enemy");
    
    std::cout << "\n=== Testing Destruction Order ===" << std::endl;
    return 0;
} 