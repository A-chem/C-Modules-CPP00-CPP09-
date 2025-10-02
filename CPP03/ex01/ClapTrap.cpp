/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:45:11 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/01 08:18:54 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unnamed"), Hit_p(10), energy_p(10), att_dmg(0)
{
    std::cout << "[Default Constructor] ClapTrap \"" << name << "\" created with 10 HP, 10 EP, 0 DMG." << std::endl;
}

ClapTrap::ClapTrap(const std::string& str) : name(str), Hit_p(10), energy_p(10), att_dmg(0)
{
    std::cout << "[Parameterized Constructor] ClapTrap \"" << name 
              << "\" created with 10 HP, 10 EP, 0 DMG." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "[Copy Constructor] ClapTrap \"" << name 
              << "\" copied from another ClapTrap." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        Hit_p = other.Hit_p;
        energy_p = other.energy_p;
        att_dmg = other.att_dmg;
    }
    std::cout << "[Copy Assignment] ClapTrap \"" << name 
              << "\" assigned from another ClapTrap." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "[Destructor] ClapTrap \"" << name << "\" has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_p == 0 || Hit_p == 0)
    {
        std::cout << "ClapTrap \"" << name << "\" has no energy or HP left to attack!" << std::endl;
        return;
    }
    energy_p--;
    std::cout << "ClapTrap \"" << name << "\" attacks \"" << target 
              << "\", causing " << att_dmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_p == 0)
    {
        std::cout << "ClapTrap \"" << name << "\" is already destroyed!" << std::endl;
        return;
    }

    if (amount >= Hit_p)
        Hit_p = 0;
    else
        Hit_p -= amount;

    std::cout << "ClapTrap \"" << name << "\" takes " << amount 
              << " points of damage! Remaining HP: " << Hit_p << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_p == 0 || Hit_p == 0)
    {
        std::cout << "ClapTrap \"" << name << "\" has no energy or HP left to repair!" << std::endl;
        return;
    }

    Hit_p += amount;
    energy_p--;

    std::cout << "ClapTrap \"" << name << "\" repairs itself, regaining " 
              << amount << " hit points! HP: " << Hit_p << std::endl;
}