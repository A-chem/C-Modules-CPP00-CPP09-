/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:41:49 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/25 15:08:36 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed signedArea(Point const &a, Point const &b, Point const &c) {
     Fixed result = (a.getX() * (b.getY() - c.getY())
                  + b.getX() * (c.getY() - a.getY())
                  + c.getX() * (a.getY() - b.getY())) / Fixed(2);
        if(result < Fixed(0))
                result = result * Fixed (-1);
        return(result);
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
        Fixed areaABC = signedArea(a,b ,c);
        
        if(areaABC == Fixed(0))
                return (false);
        Fixed areaABP = signedArea(a, b, point);
        Fixed areaACP = signedArea(a, c, point);
        Fixed areaBCP = signedArea(b, c, point);

        if(areaBCP == Fixed(0) || areaACP == Fixed(0) || areaABP == Fixed(0))
                return (false);
       
        return(areaABC == areaABP + areaACP + areaBCP);
}