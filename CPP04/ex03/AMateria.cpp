/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:04:48 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/07 16:14:55 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("D_type")
{
    std::cout << "[Default Constructor] AMateria" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "[Param Constructor] AMateria" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
    std::cout << "[Copy Constructor] AMateria" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
     std::cout << "[Copy Assignment] AMateria" << std::endl;
    return(*this);
}

AMateria::~AMateria()
{
    std::cout << "[Destructor] AMateria" << std::endl;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}