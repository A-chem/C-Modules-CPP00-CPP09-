/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:07:07 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/13 14:33:26 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &t) : type(t){};

Weapon::~Weapon(){};

void Weapon::setType(const std::string &newType)
{
    type = newType;
}
const std::string& Weapon::getType(void) const
{
    return (type);
}