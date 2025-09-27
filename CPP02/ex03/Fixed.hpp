/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:32:01 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/24 10:25:46 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int _fracBits = 8;
    public:
        Fixed();
        Fixed(const int i_v);
        Fixed(const float f_v);
        Fixed(const Fixed& ether);
        Fixed& operator=(const Fixed& ether);
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
        Fixed& operator++();    
        Fixed operator++(int);  
        Fixed& operator--();   
        Fixed operator--(int);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int raw);
        float toFloat(void) const;
        int toInt(void) const;

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

    };

    std::ostream& operator<<(std::ostream& os, const Fixed& obj);


#endif 