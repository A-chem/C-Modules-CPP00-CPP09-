/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:40:38 by achemlal          #+#    #+#             */
/*   Updated: 2025/08/07 17:47:58 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *Z = newZombie("Heap_Zombie");
    Z->announce();
    delete Z;
    randomChump("Stack_Zombie");
    return (0);
}