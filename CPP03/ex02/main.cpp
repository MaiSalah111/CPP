/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:12:34 by maiahmed          #+#    #+#             */
/*   Updated: 2024/12/31 16:12:48 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "\n=== Testing Construction Order ===" << std::endl;
    FragTrap frag("Fraggy");
    
    std::cout << "\n=== Testing FragTrap Abilities ===" << std::endl;
    frag.attack("Enemy");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();
    
    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    FragTrap frag2(frag);
    frag2.highFivesGuys();
    
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 50; ++i) {
        frag.attack("Enemy");
    }
    
    std::cout << "\n=== Testing Fatal Damage ===" << std::endl;
    frag.takeDamage(200);
    frag.attack("Enemy");
    frag.highFivesGuys();
    
    std::cout << "\n=== Testing Destruction Order ===" << std::endl;
    return (0);
}