/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:52:44 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/02 18:05:11 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const std::string &str);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void makeSound() const;
};

#endif  