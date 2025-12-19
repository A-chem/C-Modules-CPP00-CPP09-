#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class AFORM_HPP
{
    private:
        const std::string   name;
        bool                signe;
        int const           grade_s;
        int const           grade_ex;
    public:
        virtual void beSigned(const Bureaucrat& obj) = 0;
        virtual execute(Bureaucrat const & executor) const = 0;

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

#endif