/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:42:28 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/08 10:17:11 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() 
{
    for(int i = 0; i < 4 ; i++)
    {
        inventory[i] = NULL;
        in_ads[i] = NULL;
    }
    std::cout << "[Default Constructor] Character" << std::endl;
}

Character::Character(std::string const & name): name(name)
{
    for(int i = 0; i < 4 ; i++)
    {
        inventory[i] = NULL;
        in_ads[i] = NULL;
    }
    std::cout << "[Param Constructor] Character" << std::endl;
}

Character::Character(const Character& other)
{
    name = other.name;
    for(int i = 0; i < 4; i++)
    {
      if(inventory[i])
        inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    std::cout << "[Copy Constructor] Character" << std::endl;
} 

Character& Character::operator=(const Character& other)
{
    
    if(this != &other)
    {
        name = other.name;
        for(int i = 0; i < 4; i++)
        {
            delete inventory[i];
            if(other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
        }
    }
    std::cout << "[Copy Assignment] Character" << std::endl;
    return (*this);
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
    {
        delete inventory[i];
        delete in_ads[i];
    }
    std::cout << "[Destructor] Character" << std::endl;
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(AMateria *m)
{
    if(!m || inventory[3])
        return ;
    for(int i = 0; i < 4; i++)
    {
        if(!inventory[i])
        {
            inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    in_ads[idx] = inventory[idx];
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}
