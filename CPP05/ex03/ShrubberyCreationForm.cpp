#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
    AForm("ShrubberyCreationForm", "default_target", 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& tgt): 
    AForm("ShrubberyCreationForm", tgt, 145, 137){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): 
    AForm(other){};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if(this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void ShrubberyCreationForm::execute(const Bureaucrat& obj)
{
    if(!getSigne())
        throw FormNotSignedException();
    if(obj.getGrade() > getGrade_ex())
        throw GradeTooLowException();

    std::ofstream file(getTarget()+ "Shrubbery");
    if (!file.is_open())
       throw std::runtime_error("File creation failed!");

    file << "   @@@     @@@     @@@\n";
    file << "  @@@@@   @@@@@   @@@@@\n";
    file << " @@@@@@@ @@@@@@@ @@@@@@@\n";
    file << "    |       |       |\n";
    file << "    |       |       |\n";
    file << "   ~~~     ~~~     ~~~\n";
    file << "  ~~~~~   ~~~~~   ~~~~~\n";
    file.close(); 
}