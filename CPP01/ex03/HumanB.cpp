/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:28:00 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/13 14:30:45 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &n) : name(n) , Wpn(NULL){};

HumanB::~HumanB(){};

void HumanB::attack()
{
    if (!Wpn)
        std::cout << " has no weapon to attack with!" << std::endl;
    else
        std::cout << name << " attacks with their " << Wpn->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &w)
{
    Wpn = &w;
}
