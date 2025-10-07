/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:07:04 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/07 17:50:38 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string const & type);
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
