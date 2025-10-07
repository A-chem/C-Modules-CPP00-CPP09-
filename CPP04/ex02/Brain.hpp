/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 08:57:48 by achemlal          #+#    #+#             */
/*   Updated: 2025/10/06 15:13:46 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP 
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const std::string& ideas);
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif 