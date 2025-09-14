/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:12:30 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/13 14:29:51 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &n, Weapon &w) : name(n), Wpn(w){};

HumanA::~HumanA(){};

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << Wpn.getType() << std::endl;
}