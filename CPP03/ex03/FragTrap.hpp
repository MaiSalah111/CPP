/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:15:06 by maiahmed          #+#    #+#             */
/*   Updated: 2024/12/31 16:15:07 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    ~FragTrap();
    
    FragTrap& operator=(const FragTrap& other);

    void highFivesGuys(void);
};

#endif