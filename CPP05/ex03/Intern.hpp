#ifndef INTERN_HPP
#define INTERN_HPP


#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp"

class Intern
{
    private :
        AForm* createShrubberyCreationForm(const std::string& targetForm) const;
        AForm* createRobotomyRequestForm(const std::string& targetForm) const;
        AForm* createPresidentialPardonForm(const std::string& targetForm) const;
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& name, const std::string& target) const;

        class FormNotFoundException : public std::exception
        {
            private:
                const std::string msg;
            public:
                FormNotFoundException(const std::string m);
                ~FormNotFoundException() throw();
                const char* what() const throw();
        };
};

#endif