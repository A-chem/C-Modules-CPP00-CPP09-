/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:12:45 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/16 14:56:43 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : fixed_point(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int n)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->fixed_point = n << 8;
}
Fixed::Fixed(float n)
{
    std::cout<<"Float constructor called"<<std::endl;
 fixed_point = roundf(n * 256);   
}

Fixed::Fixed(const Fixed& other)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if(this != &other)
        this->fixed_point = other.fixed_point;
    return (*this);
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
float Fixed::toFloat(void) const
{
    return(this->fixed_point / 256.0f);
}

int Fixed::toInt(void) const
{
    return (fixed_point >> 8);
}

std::ostream& operator<<(std::ostream &os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}