/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:05:55 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/06 15:23:16 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "Brain.hpp"

 Brain::Brain() 
 {
   for(int i = 0; i < 100; i++)
      ideas[i] = "ideas"; 
     std::cout << "[Default Constructor] Brain" << std::endl;
 }
 
 Brain::Brain(const std::string& ideas)
 {
   int len = ideas.length();
   for(int i = 0; i < len; i++)
      this->ideas[i] = ideas[i];
    std::cout << "[Parameter Constructor] Brain" << std::endl;
 }
 Brain::Brain(const Brain& other)
 {
    *this = other;
    std::cout << "[Copy Constructor] Brain" << std::endl;
 }
 Brain& Brain::operator=(const Brain& other)
 {
   int len = other.ideas->length();
   if(this != &other)
   {
      for(int i = 0; i < len; i++)
         this->ideas[i] = other.ideas[i];
   }
   std::cout << "[Copy Assignment] Brain" << std::endl;
   return (*this);
 }

 Brain::~Brain()
 {
    std::cout << "[Destructor] Brain" << std::endl;
 }

void Brain::setIdea(int index, const std::string& idea)
{
     if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}