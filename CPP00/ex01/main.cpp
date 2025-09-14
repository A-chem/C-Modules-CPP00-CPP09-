/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:34:49 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/14 14:07:39 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int  main()
{
	PhoneBook	pb;
	std::string	cmd;
	
	while(true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break ;
		if (cmd == "ADD")
            pb.addContact();
        else if (cmd == "SEARCH")
             pb.searchContact();
        else if (cmd == "EXIT")
            break;
	}
	return (0);
}