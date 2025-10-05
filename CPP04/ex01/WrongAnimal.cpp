/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:27:26 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/02 18:32:05 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Non-type")
{
    std::cout << "[Default Constructor] WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& str) : type(str)
{
    std::cout << "[Default Constructor] WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    *this = other;
      std::cout << "[Copy Constructor] WrongAnimal" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
     std::cout << "[Copy Assignment] WrongAnimal" << std::endl;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
     std::cout << "[Destructor] WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "*wrong animal sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}
