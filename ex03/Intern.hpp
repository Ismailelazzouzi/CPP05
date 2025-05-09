#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
private:
    std::string type[3];
    AForm* createShrubbery(std::string const &target) const;
    AForm* createRobotomy(std::string const &target) const;
    AForm* createPresidential(std::string const &target) const;
public:
    Intern();
    Intern(std::string rrf, std::string ppf, std::string scf);
    ~Intern();
    AForm    *makeForm(std::string const &name, std::string const &target) const;
};
