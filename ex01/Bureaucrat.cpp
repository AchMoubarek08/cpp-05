
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "Default constructor called" << std::endl;
}


Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        _grade = rhs._grade;
    return *this;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}   
void Bureaucrat::signForm(Form &form)
{
    if(form.getSigned() == 0)
    {
        if (form.getGradeToSign() >= _grade)
        {
            form.beSigned(*this);
            std::cout << _name << " signs " << form.getName() << std::endl;
        }
        else
            std::cout << _name << " cannot sign " << form.getName() << " because grade is too low" << std::endl;
    }
    else
        std::cout << _name << " cannot sign " << form.getName() << " because form is already signed" << std::endl;
}
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return o;
}
