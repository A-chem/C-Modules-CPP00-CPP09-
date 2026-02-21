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

RobotomyRequestForm::RobotizationFailed::RobotizationFailed(const std::string m): msg(m) {}
RobotomyRequestForm::RobotizationFailed::~RobotizationFailed() throw() {}
const char* RobotomyRequestForm::RobotizationFailed::what() const throw()
{
    return (msg.c_str());
}

void RobotomyRequestForm::execute(const Bureaucrat& obj) const
{
    if (!getSigne())
        throw FormNotSignedException("Form must be signed before execution");

    if (obj.getGrade() > getGrade_ex())
        throw GradeTooLowException("Executor grade too low");

   std::cout << "Brrrrr... zzzzz..." << std::endl;
   srand(time(NULL));
   int nbr = rand() % 2;
   if(nbr == 1)
        std::cout << "Target has been robotomized successfully!" << std::endl;
    else throw RobotizationFailed("Robotomy failed: drilling process unsuccessful.");

}
