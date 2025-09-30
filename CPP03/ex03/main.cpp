/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:29:46 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/30 08:27:02 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n--- Testing Default Constructor ---\n";
    DiamondTrap diamond;  

    std::cout << "\n--- Testing attack ---\n";
    diamond.attack("Target1");       
    diamond.takeDamage(20);          
    diamond.beRepaired(10);          

    std::cout << "\n--- Testing special abilities ---\n";
    diamond.guardGate();            
    diamond.highFivesGuys();         
    diamond.whoAmI();                

    std::cout << "\n--- Testing Parameterized Constructor ---\n";
    DiamondTrap paramDiamond("Ruby");   
    paramDiamond.whoAmI();

    std::cout << "\n--- Testing Copy Constructor ---\n";
    DiamondTrap copyDiamond(diamond);   
    copyDiamond.whoAmI();

    std::cout << "\n--- Testing Assignment Operator ---\n";
    DiamondTrap assignedDiamond("Temp");  
    assignedDiamond = diamond;            
    assignedDiamond.whoAmI();

    std::cout << "\n--- End of main, destructors will be called ---\n";

    return 0;
}



