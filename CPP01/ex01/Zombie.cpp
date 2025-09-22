/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:31:24 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/20 09:37:49 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::Zombie(std::string n) : name(n)
{
    std::cout<< name << " is born " << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed " << std::endl;
}

void Zombie::announce(void)
{
    std::cout<< name <<": BraiiiiiiinnnzzzZ..."<<std::endl;
}