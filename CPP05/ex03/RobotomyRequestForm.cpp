#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() :
    AForm("RobotomyRequestForm", "default_target", 72, 52) {};

RobotomyRequestForm::RobotomyRequestForm(const std::string& tgt): 
    AForm("RobotomyRequestForm", tgt, 72, 45){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): 
    AForm(other){};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){};

void RobotomyRequestForm::execute(const Bureaucrat& obj)
{
    if(!getSigne())
        throw FormNotSignedException();
    if(obj.getGrade() > getGrade_ex())
        throw GradeTooLowException();

   std::cout << "Brrrrr... zzzzz..." << std::endl;
   std::srand(std::time(NULL));
   int nbr = rand() % 2;
   if(nbr == 1)
        std::cout << "Target has been robotomized successfully!" << std::endl;
    else throw RobotizationFailed();
}

const char *RobotomyRequestForm::RobotizationFailed::what() const throw()
{
	return ("Robotomy failed!");
}