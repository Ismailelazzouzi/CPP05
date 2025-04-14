#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("unnamed"), signGrade(150), exeGrade(150), isSigned(false)
{
}

Form::Form(const std::string &name, const int signGrade, const int exeGrade) : name(name), signGrade(signGrade), exeGrade(exeGrade), isSigned(false)
{
    if (signGrade < 1 || exeGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || exeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), signGrade(other.signGrade), exeGrade(other.exeGrade), isSigned(other.isSigned)
{

}

Form &Form::operator=(const Form &other)
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

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade Is Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade Is Too Low");
}

const std::string Form::getName() const
{
    return (this->name);
}

int Form::getSignGrade() const
{
    return (this->signGrade);
}

int Form::getexeGrade() const
{
    return (this->exeGrade);
}

bool    Form::getState() const
{
    return (this->isSigned);
}

void    Form::beSigned(Bureaucrat const &Bureaucrat)
{
    if (this->getState())
    {
        std::cout << "Form : " << this->getName() << " is Already Signed" << std::endl;
        return ;
    }
    if (Bureaucrat.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    this->isSigned = true;
    std::cout << Bureaucrat << " Signed " << this->getName() << std::endl;
}

std::ostream    &operator<<(std::ostream &out, Form &obj)
{
    std::string state;

    if (obj.getState())
        state = "YES";
    else
        state = "NO";
    out << "Form Name : " << obj.getName() << "\nSigned? : " << state << "\nGrade Required To Sign it : " << obj.getSignGrade() << "\nGrade Required To Execute It : " << obj.getexeGrade();
    return (out);
}


Form::~Form()
{
}