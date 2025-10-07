/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:24:26 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/07 17:52:34 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"
class ICharacter;


class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        std::string const & getType() const;
};



#endif 