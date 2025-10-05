/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:30:23 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/02 18:05:17 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const std::string &str);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
        void makeSound() const;
};

#endif  