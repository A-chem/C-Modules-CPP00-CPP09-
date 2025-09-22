/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:40:04 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/16 10:38:43 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int fixed_point;
    static const int _fracBits;
public:
    Fixed();
    Fixed(const Fixed& ether);
    Fixed& operator=(const Fixed& ether);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int raw);

};


#endif 