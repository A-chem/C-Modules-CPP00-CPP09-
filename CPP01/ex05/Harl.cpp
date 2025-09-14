/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:01:17 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/14 12:28:47 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<<std::endl;
}

void Harl::info(void)
{
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning(void)
{
    std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."<<std::endl;
}

void Harl::error(void)
{
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    void (Harl::*ptr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
        {
            (this->*ptr[i])();  
            return;
        }
    }
    std::cout << "Invalid level: please choose DEBUG, INFO, WARNING, or ERROR."<<std::endl;
}
