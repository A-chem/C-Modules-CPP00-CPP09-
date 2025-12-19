/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:57:56 by achemlal          #+#    #+#             */
/*   Updated: 2025/12/18 10:05:47 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
    std::cout << "===== VALID CREATION =====" << std::endl;
    try
    {
        Bureaucrat a("Obj1", 1);
        Bureaucrat b("Obj2", 150);
        Bureaucrat c("Obj3", 75);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== INVALID CREATION =====" << std::endl;
    try
    {
        Bureaucrat d("obj4", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat e("obj5", 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== INCREMENT TEST =====" << std::endl;
    try
    {
        Bureaucrat f("obj6", 2);
        std::cout << f << std::endl;
        f.Increment();
        std::cout << "After increment: " << f << std::endl;
        f.Increment();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== DECREMENT TEST =====" << std::endl;
    try
    {
        Bureaucrat g("obj7", 149);
        std::cout << g << std::endl;
        g.Decrement();
        std::cout << "After decrement: " << g << std::endl;
        g.Decrement(); 
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}