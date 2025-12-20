

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        Bureaucrat(int g);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string getName() const;
         int getGrade() const;

        void Increment();
        void Decrement();

        void signForm(AForm& obj);
        void executeForm(AForm& obj);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif