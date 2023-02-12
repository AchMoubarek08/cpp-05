#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    private:
        std::string const _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
        ~ShrubberyCreationForm();
        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;
        void getSigned() const;
};
// operator = overload
// std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);
#endif