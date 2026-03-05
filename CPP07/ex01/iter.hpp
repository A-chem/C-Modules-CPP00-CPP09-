/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:32:43 by achemlal          #+#    #+#             */
/*   Updated: 2026/03/05 22:32:44 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(T& a)
{
    std::cout << a << std::endl;
}

template <typename T>
void iter(T* arr,  const size_t len, void (*f)(T&))
{
    if(!arr)
        return ;
    for(size_t i = 0; i < len; i++)
        f(arr[i]);
}

#endif