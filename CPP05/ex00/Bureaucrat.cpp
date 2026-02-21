/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:58:06 by achemlal          #+#    #+#             */
/*   Updated: 2025/12/14 11:58:08 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Defaukt_B"), grade(150) {};

Bureaucrat::Bureaucrat(const std::string n, int g): name(n), grade(g)
{
    if (grade < 1)
        throw GradeTooHighException("Bureaucrat grade is above maximum allowed (1)");

    if (grade > 150)
        throw GradeTooLowException("Bureaucrat grade is below minimum allowed (150)");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
        this->grade = other.grade;
    return(*this);
}

Bureaucrat::~Bureaucrat(){};


const std::string Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

void Bureaucrat::Increment()
{
    if (grade == 1)
        throw GradeTooHighException("Cannot increment: grade is already at highest level (1)");

    --grade;
}

void Bureaucrat::Decrement()
{
    if (grade == 150)
        throw GradeTooLowException("Cannot decrement: grade is already at lowest level (150)");
    ++grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string m) : msg(m){};
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){};
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return(msg.c_str());
}
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string m) : msg(m){};
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){};
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return(msg.c_str());
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
} 