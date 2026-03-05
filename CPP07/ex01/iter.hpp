#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(T& a)
{
    std::cout << a << std::endl;
}

template <typename T>
void iter(T* arr,  size_t len, void (*f)(T&))
{
    for(size_t i = 0; i < len; i++)
    {
        (*f)(arr[i]);
    }
}

#endif