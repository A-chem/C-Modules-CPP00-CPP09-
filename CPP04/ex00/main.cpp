/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:23:20 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/02 18:42:14 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl; 

    i->makeSound(); 
    j->makeSound(); 
    meta->makeSound(); 

    delete meta;
    delete j;
    delete i;

    std::cout << "---- Wrong animals ----\n";

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl; 
    wrongCat->makeSound(); 

    delete wrongMeta;
    delete wrongCat;

    return 0;
}