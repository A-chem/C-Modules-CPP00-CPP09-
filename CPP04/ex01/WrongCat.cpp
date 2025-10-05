/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:32:38 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/02 18:45:13 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "[Default Constructor] WrongCat" << std::endl;
}

WrongCat::WrongCat(const std::string& str) : WrongAnimal(str)
{
    std::cout << "[Default Constructor] WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "[Copy Constructor] WrongCat" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if(this!= &other)
        WrongAnimal::operator=(other);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "[Destructor] WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Meow!" << std::endl;
}