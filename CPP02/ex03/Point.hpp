/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:33:08 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/23 16:04:55 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class Point {
private:
    Fixed const x;
    Fixed const y;
public:
    
    Point();                            
    Point(float const &x, float const &y);           
    Point(const Point& other);        
    Point& operator=(const Point& other); 
    ~Point();

    Fixed getX() const;
    Fixed getY() const;                                   
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif 