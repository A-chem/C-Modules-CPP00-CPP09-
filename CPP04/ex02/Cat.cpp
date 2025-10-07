/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:36:04 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/06 15:32:26 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("D_Cat"), brain(new Brain())
{
    std::cout << "[Default Constructor] Cat" << std::endl;
}

Cat::Cat(const std::string& str, const std::string& ideas) : Animal(str),  brain(new Brain(ideas))
{
    std::cout << "[Parameter Constructor] Cat" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) , brain(new Brain(*other.brain))
{
    std::cout << "[Copy Constructor] Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if(this!= &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "[Copy Assignment] Cat" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "[Destructor] Cat" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const 
{
    return brain;
}