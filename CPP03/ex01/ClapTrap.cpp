/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:45:11 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/24 16:49:20 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str): name(str), Hit_p(10), energy_p(10), att_dmg(0)
{
    std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(energy_p == 0 || Hit_p == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or HP left to attack!" << std::endl;
        return ;
    }
    energy_p--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << att_dmg << " points of damage!" << std::endl;
    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(energy_p == 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return ;
    }
    if(amount >= Hit_p)
        Hit_p = 0;
    else
        Hit_p -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining HP: " << Hit_p << std::endl;
    }

void ClapTrap::beRepaired(unsigned int amount)
{
    if(energy_p == 0 || Hit_p == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or HP left to repair!" << std::endl;
        return ;
    }
    Hit_p += amount;
    energy_p--;
    std::cout << "ClapTrap " << name << " repairs itself, regaining "<< amount << " hit points! HP: " << Hit_p << std::endl;
}

void ClapTrap::setHit_p(int hp)
{
    Hit_p = hp;
}

void ClapTrap::setEnergy_p(int ep)
{
    energy_p = ep;
}

void ClapTrap::setAtt_dmg(int ad)
{
    att_dmg = ad;
}

std::string ClapTrap::getName(void) const
{
    return (name); 
}

int ClapTrap::getHit_p(void) const
{
    return (Hit_p);
}

int ClapTrap::getEnergy_p(void) const
{
    return (energy_p);
}

int ClapTrap::getAtt_dmg(void) const
{
    return (att_dmg);
}