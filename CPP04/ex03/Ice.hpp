/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:17:24 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/07 17:50:44 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
   public:
        Ice();
        Ice(std::string const & type);
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif