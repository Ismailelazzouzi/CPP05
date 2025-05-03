#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("shrubbery", 145, 137)
{
    this->target = other.target;
}

const std::string ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

bool    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > 137)
        throw AForm::GradeTooLowException();
    else if (executor.getGrade() < 1)
        throw AForm::GradeTooHighException();
    std::string ext = "_shrubbery";
    std::string filename = target + ext;
    std::cout << filename << std::endl;
    std::ofstream MyFile(filename);
    if (!MyFile.is_open())
    {
        std::cerr << "Error opening file !" << std::endl;
        return (false);
    }
    MyFile << "ASCII trees";
    return (true);
}