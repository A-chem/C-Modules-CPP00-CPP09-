#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;

    try {

        
        AForm* form1 = someRandomIntern.makeForm("shrubbery_creation", "Home");
        delete form1;

        AForm* form2 = someRandomIntern.makeForm("robotomy_request", "Bender");
        delete form2;

        AForm* form3 = someRandomIntern.makeForm("presidential_pardon", "Alice");
        delete form3;
        
        AForm* form4 = someRandomIntern.makeForm("invalid_form", "Nobody");
        delete form4;
    }
    catch (const Intern::FormNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
