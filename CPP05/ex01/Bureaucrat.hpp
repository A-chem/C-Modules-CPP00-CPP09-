/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:32:13 by achemlal          #+#    #+#             */
/*   Updated: 2025/12/18 15:32:15 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string n, int g);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string getName() const;
         int getGrade() const;

        void Increment();
        void Decrement();

        void signForm(Form& obj);

         class GradeTooHighException : public std::exception
        {
            private:
                const std::string msg;
            public:
                GradeTooHighException(const std::string m);
                virtual ~GradeTooHighException() throw();
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            private:
                const std::string msg;
            public:
                GradeTooLowException(const std::string m);
                virtual ~GradeTooLowException() throw();
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif