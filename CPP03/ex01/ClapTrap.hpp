/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:44:52 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/24 16:48:06 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string.h>

class ClapTrap
{
    private:
        std::string name;
        unsigned int Hit_p;
        unsigned int energy_p;
        unsigned int att_dmg;
    public:
        ClapTrap(std::string str);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setHit_p(int hp);
        void setEnergy_p(int ep);
        void setAtt_dmg(int ad);
        std::string getName(void) const ;
        int getHit_p(void) const;
        int getEnergy_p(void) const;
        int getAtt_dmg(void) const;
        

};


#endif 