

#include "Bureaucrat.hpp"
int main()
{

    try
    {
        std::cout << "=== Creating Bureaucrats ===" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 100);

        std::cout << boss << std::endl;
        std::cout << worker << std::endl;

        std::cout << "\n=== Creating Forms ===" << std::endl;
        Form secret("SecretForm", 50, 20);
        Form easy("EasyForm", 120, 100);

        std::cout << secret << std::endl;
        std::cout << easy << std::endl;

        std::cout << "\n=== Signing Forms ===" << std::endl;

        worker.signForm(secret);   
        boss.signForm(secret);     
        worker.signForm(easy);   
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}