/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 08:59:25 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/02 18:12:33 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP 
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const std::string& str);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
};

#endif 