#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <fstream>


class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
    const std::string getTarget() const;
    bool    execute(Bureaucrat const & executor) const;
};

