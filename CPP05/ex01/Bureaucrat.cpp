/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:32:03 by achemlal          #+#    #+#             */
/*   Updated: 2025/12/18 15:32:06 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("unknow"), grade(150) {};

Bureaucrat::Bureaucrat(const std::string n, int g):name(n), grade(g)
{
    if(grade < 1) throw GradeTooHighException();
    if(grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this == &other)
        return(*this);
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
    if(grade == 1) throw GradeTooHighException();
    else
        this->grade--;

}

void Bureaucrat::Decrement()
{
    if(grade == 150) throw GradeTooLowException();
    else
        this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low");
}

void Bureaucrat::signForm(Form& obj)
{
    try
	{
		obj.beSigned(*this);
	}
	catch(const std::exception& e)
	{
        std::cout << name << " failed to sign " << obj.getName() 
          << ": " << e.what() << std::endl;
		return ;
	}
	std::cout << name << " signed " << obj.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << " bureaucrat grade " << obj.getGrade();
    return os;
} 