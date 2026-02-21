#include "AForm.hpp"

AForm::AForm() : name("Default_name"), target("Default_target"),
    signe(false), grade_s(150), grade_ex(150){};

AForm::AForm(const std::string& n, std::string tgt, const int g_s, const int g_ex) : 
    name(n), target(tgt), signe(false), grade_s(g_s), grade_ex(g_ex)
{
      if (g_s < 1 || g_ex < 1)
        throw GradeTooHighException("Form construction failed: grade above maximum authority");
    if (g_s > 150 || g_ex > 150)
        throw GradeTooLowException("Form construction failed: grade below minimum authority");
}

AForm::AForm(const AForm& other):
    name(other.name), target(other.target), signe(other.signe),
        grade_s(other.grade_s), grade_ex(other.grade_ex){};

AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
    {
        this->target = other.target;
        this->signe = other.signe;
    }
    return (*this);
}

AForm::~AForm(){};

const std::string AForm::getName() const
{
    return(name);
}
std::string AForm::getTarget() const
{
    return(target);
}
bool AForm::getSigne() const
{
    return(signe);
}

int AForm::getGrade_s() const
{
    return(grade_s);
}

int AForm::getGrade_ex() const
{
    return(grade_ex);
}

AForm::GradeTooHighException::GradeTooHighException(const std::string m) : msg(m){};
AForm::GradeTooHighException::~GradeTooHighException() throw(){};
const char* AForm::GradeTooHighException::what() const throw()
{
    return(msg.c_str());
}
AForm::GradeTooLowException::GradeTooLowException(const std::string m) : msg(m){};
AForm::GradeTooLowException::~GradeTooLowException() throw(){};
const char* AForm::GradeTooLowException::what() const throw()
{
    return(msg.c_str());
}

AForm::FormNotSignedException::FormNotSignedException(const std::string m) : msg(m){};
AForm::FormNotSignedException::~FormNotSignedException() throw(){};
const char* AForm::FormNotSignedException::what() const throw()
{
    return(msg.c_str());
}



void AForm::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() <= grade_s)
        signe = true;
    else
        throw GradeTooLowException("Bureaucrat grade too low to sign this form");
}
std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << "Form " << obj.getName()
       << "target " << obj.getTarget()
       << ", signed: " << obj.getSigne()
       << ", grade to sign: " << obj.getGrade_s()
       << ", grade to execute: " << obj.getGrade_ex();
    return (os);
}