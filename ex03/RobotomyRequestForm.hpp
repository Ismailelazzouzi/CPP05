#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <fstream>


class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
    const std::string getTarget() const;
    bool    execute(Bureaucrat const & executor) const;
};

