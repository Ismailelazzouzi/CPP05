#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    Intern someRandomIntern;
    
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    
    if (rrf) {
        
        Bureaucrat boss("Boss", 1);
        boss.signAForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    
    return 0;
}