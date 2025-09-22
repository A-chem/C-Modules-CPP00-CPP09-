/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:32:01 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/22 18:32:04 by achemlal         ###   ########.fr       */
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
    Fixed& operator<<(const Fixed& ether);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int raw);
    float toFloat(void) const;
    int toInt(void) const; 
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif 