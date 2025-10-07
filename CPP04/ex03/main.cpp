/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:32:44 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/07 17:42:18 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << "=== STEP 1: Create Materia Source ===" << std::endl;
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "=== STEP 2: Create Character 'me' ===" << std::endl;
    ICharacter* me = new Character("me");

    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "=== STEP 3: Create another character 'bob' ===" << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << "=== STEP 4: Use Materias on bob ===" << std::endl;
    me->use(0, *bob); 
    me->use(1, *bob);

    std::cout << "=== STEP 5: Unequip a Materia and use invalid slot ===" << std::endl;
    me->unequip(0);
    me->use(0, *bob); 

    std::cout << "=== STEP 6: Test deep copy of character ===" << std::endl;
    Character copy = *(dynamic_cast<Character*>(me)); 

    std::cout << "Copy uses Materia 1 on bob:" << std::endl;
    copy.use(1, *bob); 

    std::cout << "=== STEP 7: Clean up ===" << std::endl;
    delete bob;
    delete me;
    delete src;

    std::cout << "=== END OF TEST ===" << std::endl;
    return 0;
}
