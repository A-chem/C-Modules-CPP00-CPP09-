/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:11:12 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/24 17:19:51 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
    setHit_p(100);
    setEnergy_p(50);
    setAtt_dmg(20);
    std::cout << "ScavTrap "<< getName() <<" constructed!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap "<< getName() <<" desstructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAtt_dmg() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " is now is Gate keeper mode!" << std::endl;
}