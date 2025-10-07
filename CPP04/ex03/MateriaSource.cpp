/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:35:16 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/07 15:57:40 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for(int i = 0; i < 4; i++)
        if(learned[i])
            learned[i] = other.learned[i];
        else
            learned[i] = NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if(this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            if(learned[i])
            {
                delete learned[i];
                learned[i] = other.learned[i];
            }
            else
                learned[i] = NULL;
        }
    }
    return (*this);
}
MateriaSource::~MateriaSource()
{
    for(int i = 0; i > 4; i++)
        delete learned[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!learned[i])
        {
            learned[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (learned[i] && learned[i]->getType() == type)
            return learned[i]->clone();
    }
    return 0;
}