/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:35:27 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/02 07:41:20 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>


DiamondTrap::DiamondTrap() 
{
    this->Hit_p = FragTrap::Hit_p;
    this->energy_p = ScavTrap::energy_p;
    this->att_dmg = FragTrap::att_dmg;
    std::cout << "[Default Constructor] DiamondTrap \"" << name 
              << "\" created with " << Hit_p << " HP, " << energy_p << " EP, " << att_dmg << " DMG." << std::endl;
}


DiamondTrap::DiamondTrap(const std::string& str) : ClapTrap(str + "_clap_name"), ScavTrap(str), FragTrap(str), name(str)
{
    this->Hit_p = FragTrap::Hit_p;
    this->energy_p = ScavTrap::energy_p;
    this->att_dmg = FragTrap::att_dmg;
    std::cout << "[Parameterized Constructor] DiamondTrap \"" << name 
              << "\" created with " << Hit_p << " HP, " << energy_p << " EP, " << att_dmg << " DMG." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), name(other.name)
{
    std::cout << "[Copy Constructor] DiamondTrap \"" << name 
              << "\" copied from another DiamondTrap." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "[Copy Assignment] DiamondTrap \"" << name 
              << "\" assigned from another DiamondTrap." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[Destructor] DiamondTrap \"" << name << "\" has been destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
