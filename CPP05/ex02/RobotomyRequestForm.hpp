#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class  AForm;

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat& obj) const;

        class RobotizationFailed : public std::exception
		{
			private:
                const std::string msg;
            public:
                RobotizationFailed(const std::string m);
                virtual ~RobotizationFailed() throw();
				virtual const char *what() const throw();
		};

};

#endif