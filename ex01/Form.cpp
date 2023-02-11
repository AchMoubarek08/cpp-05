#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()  : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "parametrique constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream &operator << (std::ostream &o, Form const &rhs)
{
    o << "Form " << rhs.getName() << " is ";
    if (rhs.getSigned())
        o << "signed" << std::endl;
    else
        o << "unsigned and requires grade " << rhs.getGradeToSign() << " to sign and grade " << rhs.getGradeToExecute() << " to execute"<< std::endl;
    return o;
}

void Form::beSigned(Bureaucrat &aristocrat)
{
    if (aristocrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}
int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}
// form exepctions

const char *Form::GradeTooHighException::what() const throw()
{
    return "form : Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "form : Grade too low";
}
