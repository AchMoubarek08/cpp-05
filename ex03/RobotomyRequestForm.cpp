#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src), _target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const&rhs)
{
    if (this != &rhs)
    {
        Form::operator=(rhs);
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    srand(time(NULL));
    int i = rand() % 2;
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else if (Form::getSigned() == false)
        throw Form::FormNotSignedException();
    if (i == 0)
        std::cout << this->_target <<" has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << this->_target << " robotomization failed" << std::endl;
}