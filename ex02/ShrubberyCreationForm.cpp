#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubberyForm", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("shrubberyForm", 145, 137)
{
    this->target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
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
    std::ofstream MyFile(filename);
    if (!MyFile.is_open())
    {
        std::cerr << "Error opening file !" << std::endl;
        return (false);
    }
    MyFile << "      /\\\n";
    MyFile << "     /  \\\n";
    MyFile << "    /    \\\n";
    MyFile << "   /      \\\n";
    MyFile << "  /        \\\n";
    MyFile << " /          \\\n";
    MyFile << " ------------\n";
    MyFile << "      ||";
    MyFile.close();
    return (true);
}