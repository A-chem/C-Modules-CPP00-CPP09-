/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:38:30 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/16 11:36:10 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : fixed_point(0)
{
    std::cout<<"Default constructor called"<<std::endl;
};

Fixed::Fixed(const Fixed& ether)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = ether;
}

Fixed& Fixed::operator=(const Fixed& ether){
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &ether) 
        this->fixed_point = ether.getRawBits(); 
    return *this;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (this->fixed_point);
}
void Fixed::setRawBits(int fixed_point)
{
    this->fixed_point = fixed_point;
}