/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:38:41 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/07 07:46:48 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "[Default Constructor] Cure" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
    std::cout << "[Param Constructor] Cure" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "[Copy Constructor] Cure" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if(this != &other)
        AMateria::operator=(other);
     std::cout << "[Copy Assignment] Cure" << std::endl;
    return(*this);
}

Cure::~Cure()
{
    std::cout << "[Destructor] Cure" << std::endl;
}

AMateria* Cure::clone() const
{
    return(new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}