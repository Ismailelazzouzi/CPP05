#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("unnamed"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
    gradeCheck(grade);
    this->name = name;
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        name = other.name;
        grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
     return (this->grade);
}

void    Bureaucrat::gradeCheck(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void    Bureaucrat::increment()
{
    int temp;

    temp = this->grade - 1;
    gradeCheck(temp);
    this->grade = temp;
}

void    Bureaucrat::decrement()
{
    int temp;

    temp = this->grade + 1;
    gradeCheck(temp);
    this->grade = temp;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too Low!");
}

void    Bureaucrat::signAForm(AForm &AForm)
{
    AForm.beSigned(*this);
}
bool    Bureaucrat::executeForm(AForm const & form) const
{
    if (form.execute(*this))
    {
        std::cout << *this << " executed " << form.getName() << std::endl;
        return (true);
    }
    std::cout << *this << "couldn't execute " << form.getName() << std::endl;
    return (false);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (out);
}