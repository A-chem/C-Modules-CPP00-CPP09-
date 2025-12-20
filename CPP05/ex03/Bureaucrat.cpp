

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default_Bureaucrate"), grade(150) {};

Bureaucrat::Bureaucrat(int g): name("Bureaucrate")
{
  
    if(g < 1)  
        throw GradeTooHighException();
    else if(g > 150) throw GradeTooLowException();
    else
        grade = g;
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

void Bureaucrat::signForm(AForm& obj)
{
    try
	{
		obj.beSigned(*this);
        std::cout << name << " signed " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
        std::cout << name << " failed to sign " << obj.getName()
          << ": " << e.what() << std::endl;
		return ;
	}
}

void Bureaucrat::executeForm(AForm& obj)
{
    try
    {
        obj.execute(*this);
        std::cout << name << " executed " << obj.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
         std::cout << name << " failed to execute " << obj.getName() 
          << ": " << e.what() << std::endl;
          return ;
    }
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << " bureaucrat grade " << obj.getGrade();
    return os;
} 