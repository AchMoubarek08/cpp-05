#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        std::string const _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
        ~RobotomyRequestForm();
        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

#endif