/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:32:21 by achemlal          #+#    #+#             */
/*   Updated: 2025/12/18 15:32:23 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("unkow"), signe(false), grade_s(150), grade_ex(150) {};

Form::Form(const std::string n, const int g_s, const int g_ex) :
    name(n), grade_s(g_s), grade_ex(g_ex)
{
    signe = false;
    if(grade_s < 1  || grade_ex < 1) throw GradeTooHighException();
    else if(grade_s > 150  || grade_ex > 150) throw GradeTooLowException();
}

Form::Form(const Form& other):
    name(other.name), signe(other.signe), grade_s(other.grade_s), grade_ex(other.grade_ex){};

Form& Form::operator=(const Form& other)
{
    if(this == &other)
        return(*this);
    this->signe = other.signe;
    return (*this);
}

Form::~Form(){};

const std::string Form::getName() const
{
    return(this->name);
}

bool Form::getSigne() const
{
    return(this->signe);
}

int Form::getGrade_s() const
{
    return(this->grade_s);
}

int Form::getGrade_ex() const
{
    return(this->grade_ex);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Grade is too low");
}


void Form::beSigned(const Bureaucrat& obj)
{
    if(obj.getGrade() <= grade_s)
        signe = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form " << obj.getName()
       << ", signed: " << obj.getSigne()
       << ", grade to sign: " << obj.getGrade_s()
       << ", grade to execute: " << obj.getGrade_ex();
    return (os);
}