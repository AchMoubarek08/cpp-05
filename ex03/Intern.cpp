#include "Intern.hpp"

Intern::Intern()
{
    return;
}

Intern::Intern(std::string name)
{
    this->_name = name;
    return;
}

Intern::Intern(Intern const &src)
{
    *this = src;
    return;
}

Intern &Intern::operator=(Intern const &rhs)
{
    this->_name = rhs._name;
    return *this;
}

Intern::~Intern()
{
    return;
}

Form *Intern::makeForm(std::string formName, std::string target)
{
    Form *form = NULL;
    if (formName == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else if (formName == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (formName == "presidential pardon")
        form = new PresidentialPardonForm(target);
    else
        std::cout << "Intern cannot create form " << formName << std::endl;
    return form;
}