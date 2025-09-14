/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:31:33 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/14 12:24:48 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cout << "Usage: " << av[0] << " <LEVEL>\n";
        std::cout << "LEVEL can be: DEBUG, INFO, WARNING, ERROR\n";
        return 1;
    }

    Harl harl;
    harl.complain(av[1]);

    return 0;
}