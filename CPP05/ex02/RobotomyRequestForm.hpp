#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class  AForm;

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat& obj);

        class RobotizationFailed : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif