/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:31:43 by achemlal          #+#    #+#             */
/*   Updated: 2025/08/18 17:24:44 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string n) : name(n)
{
    std::cout<< name << " is born 🧟‍♂️" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed 💀" << std::endl;
}

void Zombie::announce( void )
{
    std::cout<< name <<": BraiiiiiiinnnzzzZ..."<<std::endl;
}