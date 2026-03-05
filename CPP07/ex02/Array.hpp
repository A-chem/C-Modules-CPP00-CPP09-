/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:32:52 by achemlal          #+#    #+#             */
/*   Updated: 2026/03/05 22:32:53 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <exception>

template <typename T>

class Array
{
    private:
        T*        numbers;
        unsigned int len;
    public: 
        Array(): numbers(NULL), len(0){};
        Array(unsigned int n): numbers(new T[n]), len(n){};
        Array(const Array<T>& other)
        {
            len = other.len;
            numbers = new T[len];
            for(unsigned int i = 0; i < len; i++)
                numbers[i] = other.numbers[i];
        };
        Array& operator=(const Array<T>& other)
        {
            if(this != &other)
            {
                delete[] numbers;
                len = other.len;
                numbers = new T[len];
                for(unsigned int i = 0; i < len; i++)
                    numbers[i] = other.numbers[i];
            }
            return *this;
        }
        ~Array(){delete numbers;};

        class SizeOutOfBounds : public std::exception
        {
            private:
                const std::string msg;
            public:
                SizeOutOfBounds(const std::string& m): msg(m){};
                virtual ~SizeOutOfBounds(){};
                virtual const char* what() const throw()
                {
                    return msg.c_str();
                }
        };
        T& operator[](unsigned int idx)
        {
            if(idx >= len )
                throw SizeOutOfBounds("size is out of bounds");
            return numbers[idx];
        }
        const T& operator[](unsigned int idx) const 
        {
            if(idx >= len )
                throw SizeOutOfBounds("size is out of bounds");
            return numbers[idx];
        }
        unsigned int size() const
        {
            return len;
        }




};


#endif