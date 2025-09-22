/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:31:43 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/22 18:31:46 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int i_v)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->fixed_point = i_v * (1 << _fracBits);
}

Fixed::Fixed(const float f_v)
{
    std::cout<<"Float constructor called"<<std::endl;
    this->fixed_point = roundf(f_v * (1 << _fracBits));
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
    return ((float)fixed_point / (1 << _fracBits));
}

int Fixed::toInt(void) const
{
    return(fixed_point / (1 << _fracBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
} 