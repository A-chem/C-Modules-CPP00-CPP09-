#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() :
    AForm("PresidentialPardonForm", "default_target", 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(const std::string& tgt): 
    AForm("PresidentialPardonForm", tgt, 25, 5){};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): 
    AForm(other){};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::execute(const Bureaucrat& obj)
{
    if(!getSigne())
        throw FormNotSignedException();
    if(obj.getGrade() > getGrade_ex())
        throw GradeTooLowException();

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl; 
}