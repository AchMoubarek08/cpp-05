#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
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

void Form::beSigned(Bureaucrat &aristocrat)
{
    if (aristocrat.getGrade() < _gradeToSign)
        throw Form::GradeTooHighException();
    else if (aristocrat.getGrade() > _gradeToSign)
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