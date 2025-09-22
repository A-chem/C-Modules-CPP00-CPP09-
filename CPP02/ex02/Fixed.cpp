/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:35:56 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/22 16:29:14 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0){}

Fixed::Fixed(const int i_v)
{
        this->fixed_point = i_v * (1 << _fracBits);
}

Fixed::Fixed(const float f_v)
{
    this->fixed_point = roundf(f_v * (1 << _fracBits));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    if(this != &other)
        this->fixed_point = other.fixed_point;
    return (*this);
}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const
{
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

bool Fixed::operator>(const Fixed& other) const
{
    return (this->fixed_point > other.fixed_point);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->fixed_point < other.fixed_point);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->fixed_point <= other.fixed_point);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->fixed_point >= other.fixed_point);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->fixed_point == other.fixed_point);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->fixed_point != other.fixed_point);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed obj;
    obj.setRawBits(this->fixed_point + other.fixed_point);
    return (obj);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed obj;
    obj.setRawBits(this->fixed_point - other.fixed_point);
    return (obj);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed obj;
    obj.setRawBits((this->fixed_point * other.fixed_point) / (1 << _fracBits));
    return (obj);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed obj;
    obj.setRawBits(this->fixed_point / other.fixed_point);
    return (obj);
}

Fixed& Fixed::operator++()
{
    this->fixed_point++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixed_point++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    this->fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixed_point--;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed &b)
{
    if(a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{  
    if(a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed &b)
{
    if(a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{  
    if(a > b)
        return (a);
    return (b);
}