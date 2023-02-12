#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string const _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
        ~PresidentialPardonForm();
        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

#endif