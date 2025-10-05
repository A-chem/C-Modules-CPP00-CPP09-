/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:54:05 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/02 18:45:50 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "[Default Constructor] Dog" << std::endl;
}

Dog::Dog(const std::string& str) : Animal(str)
{
    std::cout << "[Default Constructor] Dog" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Copy Constructor] Dog" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if(this!= &other)
        Animal::operator=(other);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "[Destructor] Dog" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}