/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:36:04 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/03 09:49:27 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "[Default Constructor] Cat" << std::endl;
}

Cat::Cat(const std::string& str, Brain *brain) : Animal(str) , brain(brain)
{
    std::cout << "[Parameter Constructor] Cat" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    *this = other;
    std::cout << "[Copy Constructor] Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if(this!= &other)
    {
        Animal::operator=(other);
        this->brain = other.brain;
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

Brain* Cat::getBrain(void)
{
    return (brain);
}