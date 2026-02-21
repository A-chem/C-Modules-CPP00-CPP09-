#ifndef PREISDENTIALPARDONFORM_HPP
#define PREISDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class  AForm;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat& obj) const;
};

#endif