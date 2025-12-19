/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:08:42 by achemlal          #+#    #+#             */
/*   Updated: 2025/12/18 15:07:39 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                signe;
        int const           grade_s;
        int const           grade_ex;
    public:
        Form();
        Form(const std::string n, const int g_s, const int g_ex);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        
        const std::string getName() const;
        bool getSigne() const;
        int getGrade_s() const;
        int getGrade_ex() const;

        void beSigned(const Bureaucrat& obj);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<( std::ostream& os, const Form& obj);

#endif