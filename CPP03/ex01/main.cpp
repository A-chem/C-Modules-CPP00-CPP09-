/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:22:20 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/24 17:24:23 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "---- Construction ----" << std::endl;
    ClapTrap c1("Clappy");
    ScavTrap s1("Scavy");

    std::cout << "\n---- Test attacks ----" << std::endl;
    c1.attack("target dummy");
    s1.attack("evil robot");

    std::cout << "\n---- Test taking damage ----" << std::endl;
    s1.takeDamage(30);
    s1.takeDamage(80); 

    std::cout << "\n---- Test repairing ----" << std::endl;
    s1.beRepaired(20);
    c1.beRepaired(5);

    std::cout << "\n---- Test guard mode ----" << std::endl;
    s1.guardGate();  
    
    std::cout << "\n---- Destruction ----" << std::endl;
    return 0;
}
