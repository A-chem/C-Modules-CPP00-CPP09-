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

void ShrubberyCreationForm::execute(const Bureaucrat& obj) const
{
     if (!getSigne())
        throw FormNotSignedException("Form must be signed before execution");

    if (obj.getGrade() > getGrade_ex())
        throw GradeTooLowException("Executor grade too low");

    std::ofstream file((getTarget() + "_shrubbery").c_str());
    if (!file)
        throw std::runtime_error("Failed to create shrubbery file");

    file << "   @@@     @@@     @@@\n";
    file << "  @@@@@   @@@@@   @@@@@\n";
    file << " @@@@@@@ @@@@@@@ @@@@@@@\n";
    file << "    |       |       |\n";
    file << "    |       |       |\n";
    file << "   ~~~     ~~~     ~~~\n";
    file << "  ~~~~~   ~~~~~   ~~~~~\n";
    file.close(); 
}