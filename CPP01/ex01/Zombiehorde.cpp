/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombiehorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:33:39 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/20 16:19:42 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombieHorde;
    
    if(N <= 0)
        return (NULL);
    zombieHorde =  new Zombie[N];
    for(int i = 0; i < N; i++)
        zombieHorde[i] = Zombie(name);
    return (zombieHorde);
}
