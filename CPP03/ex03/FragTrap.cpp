/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:29:25 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/30 08:20:23 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    Hit_p = 100;
    energy_p = 100;
    att_dmg = 30;
    std::cout << "[Default Constructor] FragTrap " << name 
              << " created with 100 HP, 100 EP, 30 DMG." << std::endl;
}

FragTrap::FragTrap(std::string str) : ClapTrap(str)
{
    Hit_p = 100;
    energy_p = 100;
    att_dmg = 30;
    std::cout << "[Parameterized Constructor] FragTrap " << name 
              << " created with 100 HP, 100 EP, 30 DMG." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "[Copy Constructor] FragTrap " << name 
              << " copied from another FragTrap." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "[Copy Assignment] FragTrap " << name 
              << " assigned from another FragTrap." << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "[Destructor] FragTrap " << name << " has been destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if(energy_p == 0 || Hit_p == 0)
    {
        std::cout << "FragTrap " << name << " has no energy or HP left to attack!" << std::endl;
        return ;
    }
    energy_p--;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << att_dmg << " points of damage!" << std::endl;
    
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}