/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:28:23 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/08 09:42:26 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include "ICharacter.hpp"

class Character : public ICharacter
{
    private :
        std::string name;
        AMateria* inventory[4];
        AMateria* in_ads[4];
    public:
        Character();
        Character(std::string const & name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
    };

#endif