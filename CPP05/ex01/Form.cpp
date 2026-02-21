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

Form::Form(): name("Default_F"), signe(false), grade_s(150), grade_ex(150) {};

Form::Form(const std::string n, int g_s, int g_ex): name(n),
    signe(false), grade_s(g_s), grade_ex(g_ex){
    if (g_s < 1 || g_ex < 1)
        throw GradeTooHighException("Form construction failed: grade above maximum authority");
    if (g_s > 150 || g_ex > 150)
        throw GradeTooLowException("Form construction failed: grade below minimum authority");
}

Form::Form(const Form& other):
    name(other.name), signe(other.signe), grade_s(other.grade_s), grade_ex(other.grade_ex){};

Form& Form::operator=(const Form& other)
{
    if(this != &other)
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

Form::GradeTooHighException::GradeTooHighException(const std::string m) : msg(m){};
Form::GradeTooHighException::~GradeTooHighException() throw(){};
const char* Form::GradeTooHighException::what() const throw()
{
    return(msg.c_str());
}
Form::GradeTooLowException::GradeTooLowException(const std::string m) : msg(m){};
Form::GradeTooLowException::~GradeTooLowException() throw(){};
const char* Form::GradeTooLowException::what() const throw()
{
    return(msg.c_str());
}


void Form::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() <= grade_s)
        signe = true;
    else
        throw GradeTooLowException("Bureaucrat grade too low to sign this form");
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form " << obj.getName()
       << ", signed: " << obj.getSigne()
       << ", grade to sign: " << obj.getGrade_s()
       << ", grade to execute: " << obj.getGrade_ex();
    return (os);
}