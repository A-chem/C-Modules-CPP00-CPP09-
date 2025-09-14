/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:48:20 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/14 15:22:43 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <limits>
#include "Contact.hpp"

class PhoneBook 
{
    private:
    Contact contacts[8];
    int totalContacts;

    public:
    PhoneBook();
    void addContact();
    void searchContact() const;
};
#endif 