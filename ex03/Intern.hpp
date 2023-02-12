#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        std::string _name;
    public:
        Intern();
        Intern(std::string name);
        Intern(Intern const &src);
        Intern &operator=(Intern const &rhs);
        ~Intern();
        Form *makeForm(std::string formName, std::string target);
};

#endif