/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:20:28 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/20 11:05:38 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[ DEBUG ]"<<std::endl
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger."<<std::endl
              << "I really do!\n"<<std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]"<<std::endl
              << "I cannot believe adding extra bacon costs more money."<<std::endl
              << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"<<std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]"<<std::endl
              << "I think I deserve to have some extra bacon for free."<<std::endl
              << "I’ve been coming for years whereas you started working here since last month.\n"<<std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]"<<std::endl
              << "This is unacceptable! I want to speak to the manager now.\n"<<std::endl;
}


void Harl::complain(std::string level) {
    void (Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    int index = -1;

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            index = i;
            break;
        }
    }
    switch (index) {
        case 0:
            (this->*ptr[0])();
        case 1:
            (this->*ptr[1])();
        case 2:
            (this->*ptr[2])();
        case 3:
            (this->*ptr[3])();
        break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}