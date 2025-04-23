#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    const AForm    *newAForm = new ShrubberyCreationForm();
    const Bureaucrat newB("LI7WAK", 20);

    newB.executeForm(*newAForm);
}