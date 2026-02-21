#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        std::string         target;
        bool                signe;
        int const           grade_s;
        int const           grade_ex;
    public:
        AForm();
        AForm(const std::string& n, std::string tgt, const int g_s, const int g_ex);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        
        const std::string getName() const;
        std::string getTarget() const;
        bool getSigne() const;
        int getGrade_s() const;
        int getGrade_ex() const;

        void beSigned(const Bureaucrat& obj);
        virtual void execute(Bureaucrat const & obj) const = 0;


        class GradeTooHighException : public std::exception
        {
            private:
                const std::string msg;
            public:
                GradeTooHighException(const std::string m);
                virtual ~GradeTooHighException() throw();
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            private:
                const std::string msg;
            public:
                GradeTooLowException(const std::string m);
                virtual ~GradeTooLowException() throw();
                virtual const char* what() const throw();
        };
        class FormNotSignedException : public std:: exception
        {
            private:
                const std::string msg;
            public:
                FormNotSignedException(const std::string m);
                virtual ~FormNotSignedException() throw();
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<( std::ostream& os, const AForm& obj);


#endif