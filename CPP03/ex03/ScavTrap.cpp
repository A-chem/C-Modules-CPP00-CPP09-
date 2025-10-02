/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:29:52 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/01 08:42:26 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    name = "Unnamed";
    Hit_p = 100;
    energy_p = 50;
    att_dmg = 20;
    std::cout << "[Default Constructor] ScavTrap \"" << name 
              << "\" created with 100 HP, 50 EP, 20 DMG." << std::endl;
}

ScavTrap::ScavTrap(const std::string& str) : ClapTrap(str)
{
    Hit_p = 100;
    energy_p = 50;
    att_dmg = 20;
    std::cout << "[Parameterized Constructor] ScavTrap \"" << name 
              << "\" created with 100 HP, 50 EP, 20 DMG." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "[Copy Constructor] ScavTrap \"" << name 
              << "\" copied from another ScavTrap." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    
    std::cout << "[Copy Assignment] ScavTrap \"" << name 
              << "\" assigned from another ScavTrap." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[Destructor] ScavTrap \"" << name << "\" has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_p == 0 || Hit_p == 0)
    {
        std::cout << "ScavTrap \"" << name << "\" has no energy or HP left to attack!" << std::endl;
        return;
    }
    energy_p--;
    std::cout << "ScavTrap \"" << name << "\" attacks \"" << target 
              << "\", causing " << att_dmg << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap \"" << name << "\" is now in Gate keeper mode!" << std::endl;
}
