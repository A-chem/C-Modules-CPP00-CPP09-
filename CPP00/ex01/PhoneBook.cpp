/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:35:53 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/14 14:07:43 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    totalContacts = 0;
}

void PhoneBook::addContact()
{
    int index;
    
    index = totalContacts % 8;
    contacts[index].setInfo();
    totalContacts++;
    std::cout << "✅ Contact added successfully.\n";
}

void PhoneBook::searchContact() const
{
    int         count;
    int         index;
    std::string input;

    count = 8;
    if(contacts[0].isEmpty())
    {
        std::cout << "📭 PhoneBook is empty.\n";
        return ;
    }
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
    for (int i = 0; i < count; ++i)
    {
        if(!contacts[i].isEmpty())
            contacts[i].displayShort(i);
    }
    std::cout << "Enter the index of the contact you want to see: ";
    std::getline(std::cin, input);
    if (input.length() != 1 || input[0] < '0' || input[0] > '7')
    {
        std::cout << "❌ Invalid index.\n";
        return;
    }
    index = input[0] - '0';
    if (index >= count || contacts[index].isEmpty())
    {
        std::cout << "❌ No contact at this index.\n";
        return;
    }
    std::cout << "🔍 Contact Details:\n";
    contacts[index].displayFull();    
}