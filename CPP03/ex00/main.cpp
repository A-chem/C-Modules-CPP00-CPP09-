/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:52:59 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/24 13:23:38 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Bender");

    robot.attack("Target1");
    robot.takeDamage(3);
    robot.beRepaired(5);
    robot.takeDamage(12);
    robot.attack("Target2");
    robot.beRepaired(2);

    return 0;
}
