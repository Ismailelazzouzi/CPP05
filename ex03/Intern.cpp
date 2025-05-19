#include "Intern.hpp"

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

AForm    *Intern::makeForm(std::string const &name, std::string const &target) const
{
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << "INTERN creates " << name << std::endl;
        if (name == this->type[i])
        {
            std::cout << "INTERN creates " << name << std::endl;
            switch (i)
            {
                case 0: return (createRobotomy(target));
                case 1: return (createPresidential(target));
                case 2: return (createShrubbery(target));
            }
        }
    }
    std::cout << "Error : Form type " << name << " does not exist" <<std::endl;
    return (NULL);
}

AForm   *Intern::createShrubbery(std::string const &target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm   *Intern::createRobotomy(std::string const &target) const
{
    return (new RobotomyRequestForm(target));
}

AForm   *Intern::createPresidential(std::string const &target) const
{
    return (new PresidentialPardonForm(target));
}