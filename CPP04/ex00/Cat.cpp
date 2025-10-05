/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:36:04 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/02 18:45:40 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "[Default Constructor] Cat" << std::endl;
}

Cat::Cat(const std::string& str) : Animal(str)
{
    std::cout << "[Default Constructor] Cat" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Copy Constructor] Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if(this!= &other)
        Animal::operator=(other);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "[Destructor] Cat" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}