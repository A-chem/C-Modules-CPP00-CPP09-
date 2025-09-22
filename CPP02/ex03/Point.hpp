/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:33:08 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/22 18:38:18 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

class Point
{
    private:
        const float x;
        const float y;
    public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
    
};

#endif 