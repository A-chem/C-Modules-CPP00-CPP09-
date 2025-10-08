/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:23:20 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/08 10:34:46 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    int N = 4;
    const Animal* animals[N];

    for (int i = 0; i < N; ++i) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Deleting animals ---\n";
    for (int i = 0; i < N; ++i)
        delete animals[i];

    std::cout << "\n--- Testing deep copy ---\n";
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase the cat!");
    Dog dog2 = dog1; 

    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << "\n";
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << "\n";

    return 0;
}
