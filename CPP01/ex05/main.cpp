/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:07:00 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/14 12:29:01 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ()
{
    Harl harl;
    std::string level;

    std::cout << "Enter a complaint level (DEBUG, INFO, WARNING, ERROR):\n";
    std::cout<<"> ";
    std::getline(std::cin, level);
    if (std::cin.eof()) 
        std::cout << "\n[EOF detected — exiting program.]\n";
    harl.complain(level);
}