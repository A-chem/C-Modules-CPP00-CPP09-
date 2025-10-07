/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:48:31 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/06 13:46:41 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if(ac > 1)
    {
        while(av[i])
        {
            j = 0;
            while(av[i][j])
            {
               std::cout<< (char)std::toupper(av[i][j]);
                j++;
            }
            if(i < ac - 1)
                std::cout<< " ";
            if(i ==  ac - 1)
                std::cout<< "\n";

            i++;
        }
    }
    else
        std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}