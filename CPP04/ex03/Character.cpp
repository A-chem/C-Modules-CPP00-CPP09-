/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:42:28 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/07 08:26:24 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("D_name")
{
    for(int i = 0; i < 4 ; i++)
        inventory[i] = NULL;
    std::cout << "[Default Constructor] Character" << std::endl;
}

Character::Character(std::string const & name): name(name)
{
    for(int i = 0; i < 4 ; i++)
        inventory[i] = NULL;
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
        delete inventory[i];
    std::cout << "[Destructor] Character" << std::endl;
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(AMateria *m)
{
    if(!m)
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
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}