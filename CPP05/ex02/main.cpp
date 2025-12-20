#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        std::cout << "===== CREATE BUREAUCRATS =====" << std::endl;
        Bureaucrat low(149);
        Bureaucrat mid(50);
        Bureaucrat high(1);

        std::cout << low << std::endl;
        std::cout << mid << std::endl;
        std::cout << high << std::endl;

        std::cout << "\n===== CREATE FORMS =====" << std::endl;
        ShrubberyCreationForm shrub("shurb");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
        std::cout << "\n===== SIGN FORMS =====" << std::endl;
        low.signForm(shrub);
        mid.signForm(shrub);
        high.signForm(shrub);

        low.signForm(robot);
        mid.signForm(robot);
        high.signForm(robot);

        low.signForm(pardon);
        mid.signForm(pardon);
        high.signForm(pardon);           

        std::cout << "\n===== EXECUTION =====" << std::endl;
        low.executeForm(shrub);  
        mid.executeForm(shrub);
        high.executeForm(shrub);

        low.executeForm(robot);  
        mid.executeForm(robot);
        high.executeForm(robot);

        low.executeForm(pardon);  
        mid.executeForm(pardon);
        high.executeForm(pardon);

    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
