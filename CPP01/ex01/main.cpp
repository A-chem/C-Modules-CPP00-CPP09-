/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:50:46 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/20 10:18:52 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
    Zombie *zombie;
    int N = -1;

    zombie = zombieHorde(N, "Zombie");
    for (int i = 0; i < N; i++)
	{
       std::cout << "Index " << i << ": ";
	   zombie[i].announce();
    }

	delete[] zombie;
	return (0);
}