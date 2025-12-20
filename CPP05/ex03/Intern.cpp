#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
    std::string names[3] = {
        "shrubbery_creation",
        "robotomy_request",
        "presidential_pardon"
    };

    AForm* (Intern::*creators[3])(const std::string&) const = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*creators[i])(target); 
        }
    }

    throw Intern::FormNotFoundException();  
}
