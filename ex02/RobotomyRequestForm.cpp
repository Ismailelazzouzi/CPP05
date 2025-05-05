#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyForm", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyForm", 72, 45)
{
    this->target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

const std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

bool    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getState())
        return (false);
    if (executor.getGrade() > 45)
        throw AForm::GradeTooLowException();
    else if (executor.getGrade() < 1)
        throw AForm::GradeTooHighException();
    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "the robotomy failed." << std::endl;
    return (true);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}