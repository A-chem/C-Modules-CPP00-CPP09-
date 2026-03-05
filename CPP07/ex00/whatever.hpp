/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:32:39 by achemlal          #+#    #+#             */
/*   Updated: 2026/03/05 22:32:40 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T swap;
    swap = a;
    a = b;
    b = swap;
}

template <typename T>
T& min(T& a, T& b)
{
    if(a < b)
        return a;
    return b;
}

template <typename T>
T& max(T& a, T& b)
{
    if(a > b)
        return a;
    return b;
}


#endif