/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:00:30 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/29 11:20:57 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "=== Test: Parameterized Constructor ===" << std::endl;
    FragTrap frag1("Frag_robot");

    std::cout << "\n=== Test: Default Constructor ===" << std::endl;
    FragTrap frag2;

    std::cout << "\n=== Test: Copy Constructor ===" << std::endl;
    FragTrap frag3(frag1);

    std::cout << "\n=== Test: Copy Assignment Operator ===" << std::endl;
    frag2 = frag1;

    std::cout << "\n=== Test: Inherited Functions ===" << std::endl;
    frag1.attack("Target1");
    frag1.takeDamage(40);
    frag1.beRepaired(25);

    std::cout << "\n=== Test: FragTrap Special Ability ===" << std::endl;
    frag1.highFivesGuys();

    std::cout << "\n=== End of main, destructors will be called ===" << std::endl;
    return 0;
}
