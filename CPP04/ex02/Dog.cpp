/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:54:05 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/06 15:40:34 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :  Animal("D_Dog"), brain(new Brain())
{
    std::cout << "[Default Constructor] Dog" << std::endl;
}

Dog::Dog(const std::string& str, const std::string& ideas): Animal(str), brain(new Brain(ideas))
{
    std::cout << "[Param Constructor] Dog" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "[Copy Constructor] Dog" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
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

Dog::~Dog()
{
    delete brain;
    std::cout << "[Destructor] Dog" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
Brain* Dog::getBrain() const 
{
    return brain;
}