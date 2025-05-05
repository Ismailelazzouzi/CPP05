#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    ShrubberyCreationForm shrubbery("Home");
    PresidentialPardonForm pardon("Samael");
    RobotomyRequestForm robotomy("WILL SMITH");
    const Bureaucrat newB("2IEM7ALUF", 20);
    const Bureaucrat newB1("PRESIDENT", 2);
    const Bureaucrat newB2("LM9ADEM", 40);
    newB.executeForm(shrubbery);
    newB1.executeForm(pardon);
    newB2.executeForm(robotomy);
    newB.signAForm(shrubbery);
    newB1.signAForm(pardon);
    newB2.signAForm(robotomy);
    newB.executeForm(shrubbery);
    newB1.executeForm(pardon);
    newB2.executeForm(robotomy);
}