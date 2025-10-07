/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:18:42 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/07 07:47:36 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "[Default Constructor] Ice" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type)
{
    std::cout << "[Param Constructor] Ice" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout << "[Copy Constructor] Ice" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if(this != &other)
        AMateria::operator=(other);
     std::cout << "[Copy Assignment] Ice" << std::endl;
    return(*this);
}

Ice::~Ice()
{
    std::cout << "[Destructor] Ice" << std::endl;
}

AMateria* Ice::clone() const
{
    return(new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "<<target.getName() << " *" << std::endl;
}