#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form const &src);
        Form &operator=(Form const &rhs);
        ~Form();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        std::string getName() const;
        bool getSigned() const;
        void beSigned(Bureaucrat &aristocrat);
        int getGradeToSign() const;
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);
#endif