#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const int signGrade, const int exeGrade) : AForm(name, signGrade, exeGrade)
{
    if (signGrade < 145 || exeGrade < 137)
        throw AForm::GradeTooHighException();
    if (signGrade > 145 || exeGrade > 137)
        throw AForm::GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
}

bool    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::cout << executor << " IS EXECUTING " << this->getName() << std::endl;
    return (true);
}