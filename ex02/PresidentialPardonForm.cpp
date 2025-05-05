#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PardonForm", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PardonForm", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PardonForm", 25, 5)
{
    this->target = other.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

const std::string PresidentialPardonForm::getTarget() const
{
    return (this->target);
}

bool    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getState())
        return (false);
    if (executor.getGrade() > 5)
        throw AForm::GradeTooLowException();
    else if (executor.getGrade() < 1)
        throw AForm::GradeTooHighException();
    std::cout << executor << " Informs That " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return (true);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}