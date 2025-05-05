#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    const AForm    *newAForm = new ShrubberyCreationForm("Home");
    const AForm    *newAForm1 = new PresidentialPardonForm("Samael");
    const Bureaucrat newB("2IEM7ALUF", 20);
    const Bureaucrat newB1("PRESIDENT", 2);
    newB.executeForm(*newAForm);
    newB1.executeForm(*newAForm1);
}