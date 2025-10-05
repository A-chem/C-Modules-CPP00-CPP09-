/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:23:20 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/03 10:45:16 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void f(){system("leaks Polymorphism");}

int main() {
    atexit(f);
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl; 

    // i->makeSound(); 
    // j->makeSound(); 
    // meta->makeSound(); 

    // delete meta;
    // delete j;
    // delete i;

    // std::cout << "---- Wrong animals ----\n";

    // const WrongAnimal* wrongMeta = new WrongAnimal();
    // const WrongAnimal* wrongCat = new WrongCat();

    // std::cout << wrongCat->getType() << " " << std::endl; 
    // wrongCat->makeSound(); 

    // delete wrongMeta;
    // delete wrongCat;

    std::cout << "---- Brain ----\n";

    std::string ideas[100];
    for(int i = 0; i < 100; i++)
        ideas[i] = "1";
    Brain *brain = new Brain(ideas);
    Cat *C = new Cat("Cat", brain);

    Brain *p ; 
    p  =  C->getBrain();
    std::string *str ;
    str = p->getIdeas();

    for(int i = 0; i < 100; i++)
    {
        std::cout << str[i]<< "-----" << i << std::endl;
    }
    delete C;
    // delete brain;
    // delete a;
    

    return 0;
}