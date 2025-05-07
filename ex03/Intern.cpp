#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern()
{
    this->type[0] = "robotomy request";
    this->type[1] = "presidential pardon";
    this->type[2] = "shrubbery creation";
}
Intern::Intern(std::string rrf, std::string ppf, std::string scf)
{
    this->type[0] = rrf;
    this->type[1] = ppf;
    this->type[2] = scf;
}

Intern::~Intern()
{
}

AForm    *makeForm(std::string &name, std::string &target)
{
    
}