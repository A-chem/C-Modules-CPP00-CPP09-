#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <fstream> 
#include "AForm.hpp"

class  AForm;

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void execute(const Bureaucrat& obj);
};

#endif