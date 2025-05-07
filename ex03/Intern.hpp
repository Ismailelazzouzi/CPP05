#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class AForm;

class Intern
{
private:
    std::string type[3];
public:
    Intern();
    Intern(std::string rrf, std::string ppf, std::string scf);
    ~Intern();
    AForm    *makeForm(std::string &name, std::string &target);
};
