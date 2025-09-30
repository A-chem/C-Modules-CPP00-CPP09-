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
    std::cout << "=== Test: Constructor with parameter ===" << std::endl;
    ClapTrap robot1("Sophia");

    std::cout << "\n=== Test: Default constructor ===" << std::endl;
    ClapTrap robot2;

    std::cout << "\n=== Test: Copy constructor ===" << std::endl;
    ClapTrap robot3(robot1);

    std::cout << "\n=== Test: Copy assignment operator ===" << std::endl;
    robot2 = robot1;

    std::cout << "\n=== Test: Member functions ===" << std::endl;
    robot1.attack("Target1");
    robot1.takeDamage(3);
    robot1.beRepaired(5);
    robot1.takeDamage(12); 
    robot1.attack("Target2"); 
    robot1.beRepaired(2);  

    std::cout << "\n=== End of main, destructors will be called ===" << std::endl;
    return 0;
}

