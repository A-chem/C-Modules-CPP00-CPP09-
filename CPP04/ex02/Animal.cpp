/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:12:37 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/06 15:52:54 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Non-type")
{
    std::cout << "[Default Constructor] Animal" << std::endl;
}

Animal::Animal(const std::string& str) : type(str)
{
    std::cout << "[Default Constructor] Animal" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
      std::cout << "[Copy Constructor] Animel" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
     std::cout << "[Copy Assignment] Animal" << std::endl;
    return(*this);
}

Animal::~Animal()
{
     std::cout << "[Destructor] Animal" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}
