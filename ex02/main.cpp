#include "AForm.hpp"
#include "Bureaucrat.hpp"
int main(void)
{
    AForm    newAForm;
    Bureaucrat newB;

    try{
        AForm newAForm1("AForm 1", 0, 1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    newB.signAForm(newAForm);
    std::cout << newAForm << std::endl;
    try{
        AForm newAForm1("AForm 1", 1, 2);
        newB.signAForm(newAForm1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}