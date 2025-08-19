/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:48:01 by achemlal          #+#    #+#             */
/*   Updated: 2025/08/07 17:42:07 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
    std::string name;
    public:
    Zombie(std::string name);
    ~Zombie();
    void announce( void );
};

 Zombie*    newZombie( std::string name );
 void       randomChump( std::string name );
 
#endif