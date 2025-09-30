/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:35:27 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/30 08:29:04 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name("Unnamed")
{
    this->Hit_p = FragTrap::Hit_p;
    this->energy_p = ScavTrap::energy_p;
    this->att_dmg = FragTrap::att_dmg;
    std::cout << "[Default Constructor] DiamondTrap " << name 
              << " created with 100 HP, 100 EP, 300 DMG." << std::endl;
}

DiamondTrap::DiamondTrap(std::string str) : ClapTrap(str + "_clap_name"), ScavTrap(str), FragTrap(str),  name(str)
{
    this->Hit_p = FragTrap::Hit_p;
    this->energy_p = ScavTrap::energy_p;
    this->att_dmg = FragTrap::att_dmg;
        std::cout << "[Parameterized Constructor] FragTrap " << name 
              << " created with Frag HP, Scav EP, Frag DMG." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    *this = other;
     std::cout << "[Copy Constructor] DiamondTrap " << name 
              << " copied from another DiamondTrap." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "[Copy Assignment] DiamondTrap " << name 
              << " assigned from another DiamondTrap." << std::endl;
    return(*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[Destructor] Diamondrap " << name << " has been destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}