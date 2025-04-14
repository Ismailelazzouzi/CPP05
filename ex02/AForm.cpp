#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("unnamed"), signGrade(150), exeGrade(150), isSigned(false)
{
}

AForm::AForm(const std::string &name, const int signGrade, const int exeGrade) : name(name), signGrade(signGrade), exeGrade(exeGrade), isSigned(false)
{
    if (signGrade < 1 || exeGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || exeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), signGrade(other.signGrade), exeGrade(other.exeGrade), isSigned(other.isSigned)
{

}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->signGrade = other.signGrade;
        this->exeGrade = other.exeGrade;
        this->isSigned = other.isSigned;
    }
    return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade Is Too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade Is Too Low");
}

const std::string AForm::getName() const
{
    return (this->name);
}

int AForm::getSignGrade() const
{
    return (this->signGrade);
}

int AForm::getexeGrade() const
{
    return (this->exeGrade);
}

bool    AForm::getState() const
{
    return (this->isSigned);
}

void    AForm::beSigned(Bureaucrat const &Bureaucrat)
{
    if (this->getState())
    {
        std::cout << "AForm : " << this->getName() << " is Already Signed" << std::endl;
        return ;
    }
    if (Bureaucrat.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    this->isSigned = true;
    std::cout << Bureaucrat << " Signed " << this->getName() << std::endl;
}

std::ostream    &operator<<(std::ostream &out, AForm &obj)
{
    std::string state;

    if (obj.getState())
        state = "YES";
    else
        state = "NO";
    out << "AForm Name : " << obj.getName() << "\nSigned? : " << state << "\nGrade Required To Sign it : " << obj.getSignGrade() << "\nGrade Required To Execute It : " << obj.getexeGrade();
    return (out);
}


AForm::~AForm()
{
}