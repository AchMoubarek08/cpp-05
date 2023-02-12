#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const&rhs)
{
    if (this != &rhs)
    {
        Form::operator=(rhs);
    }
    return *this;
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else if (Form::getSigned() == false)
        throw Form::FormNotSignedException();
    else
    {
        std::ofstream file;
        file.open("zbibi_shrubbery");
        file << "          v" << std::endl;
        file << "         >X<" << std::endl;
        file << "          A" << std::endl;
        file << "         d$b" << std::endl;
        file << "      .d\\$$P" << std::endl;
        file << "    .d$i$$P" << std::endl;
        file << "   .d$$@b" << std::endl;
        file << "  .d$$i$" << std::endl;
        file.close();
    }
}