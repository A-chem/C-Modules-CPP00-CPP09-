/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:33:03 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/14 14:06:30 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static std::string getInput(std::string prompt)
{
    std::string input;
    while (true)
    {
        int flag = 1;
        std::cout << prompt;
        if (!std::getline(std::cin, input))
           exit(0);
        if (!input.empty())
        {
            for (size_t i = 0; i < input.length(); i++)
            {
                if(!isprint(input[i]))
                    flag = 0;
            }
            if(flag == 1)
                return input;            
        }
        std::cout << "Field cannot be empty. Try again.\n";
    }
    return ("");
}

void Contact::setInfo()
{
    firstName = getInput("Enter first name: ");
    lastName = getInput("Enter last name: ");
    nickname = getInput("Enter nickname: ");
    phoneNumber = getInput("Enter phone number: ");
    darkestSecret = getInput("Enter darkest secret: ");
}

static std::string formatField(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displayShort(int index) const
{
        std::cout << "|" << std::setw(10) << index
            << "|" << std::setw(10) << formatField(firstName)
            << "|" << std::setw(10) << formatField(lastName)
            << "|" << std::setw(10) << formatField(nickname)
            << "|" << std::endl;
    
}

void Contact::displayFull() const
{
    std::cout << "First Name:     " << firstName << std::endl;
    std::cout << "Last Name:      " << lastName << std::endl;
    std::cout << "Nickname:       " << nickname << std::endl;
    std::cout << "Phone Number:   " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty() const
{
    if(firstName.empty())
        return (true);
    return (false);
}