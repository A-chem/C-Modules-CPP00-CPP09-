/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:30:23 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/03 09:49:33 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const std::string &str, Brain *brain);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
        void makeSound() const;
        Brain* getBrain(void);
};

#endif  