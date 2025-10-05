/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:05:55 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/03 09:22:31 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "Brain.hpp"

 Brain::Brain()
 {
     std::cout << "[Default Constructor] Brain" << std::endl;
 }
 
 Brain::Brain(std::string *ideas)
 {
    if(ideas != NULL)
    {
        for(int i = 0; i < 100; i++)
        {
            this->ideas[i] = *ideas;
            ideas++;
        }
    }
    std::cout << "[Parameter Constructor] Brain" << std::endl;
 }
 Brain::Brain(const Brain& other)
 {
    *this = other;
    std::cout << "[Copy Constructor] Brain" << std::endl;
 }
 Brain& Brain::operator=(const Brain& other)
 {
    if(this != &other)
    {
         for(int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    std::cout << "[Copy Assignment] Brain" << std::endl;
    return (*this);
 }

 Brain::~Brain()
 {
    std::cout << "[Destructor] Brain" << std::endl;
 }

 std::string* Brain::getIdeas(void)
 {
    return (ideas);
 }