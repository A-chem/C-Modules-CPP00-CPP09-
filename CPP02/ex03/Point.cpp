/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:07:39 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/23 16:16:43 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0){};

Point::Point(float const &x, float const &y): x(x), y(y){};

Point::Point(const Point& other): x(other.x), y(other.y){}

Point& Point::operator=(const Point& other)
{
    (void)other;
    return(*this);
}

Point::~Point() {}

Fixed Point::getX() const 
{ 
    return (x); 
}
Fixed Point::getY() const 
{ 
    return (y); 
}