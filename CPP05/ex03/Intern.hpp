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
            public:
                const char* what() const throw() {
                    return "Error: form name does not exist";
                }
        };
};

#endif