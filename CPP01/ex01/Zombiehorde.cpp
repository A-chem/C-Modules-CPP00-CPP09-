/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombiehorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:33:39 by achemlal          #+#    #+#             */
/*   Updated: 2025/08/18 17:50:20 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombieHorde;
    
    zombieHorde =  new Zombie[N];
    if(N <= 0)
        return (nullptr);
    for(int i = 0; i < N; i++)
        zombieHorde[i] = Zombie(name);
    return (zombieHorde);
}